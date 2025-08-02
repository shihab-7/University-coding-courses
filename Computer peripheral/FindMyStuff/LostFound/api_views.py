from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import status
from .models import LostItem, Claim, VaultSettings
from django.shortcuts import get_object_or_404
from .utils import generate_otp
from users.validators import validate_student_id

@api_view(['POST'])
def verify_mcq(request,item_id):
    item = get_object_or_404(LostItem, id=item_id)
    data = request.data

    if item.status != 'Unclaimed':
        return Response({"error": f"This item has already been claimed or resolved. Status: {item.status}"}, status=status.HTTP_400_BAD_REQUEST)

    ans1 = data.get('answer_1')  
    ans2 = data.get('answer_2')
    student_id = data.get('student_id')

    # Validate student ID format first
    if not student_id:
        return Response({"error": "Student ID is required."}, status=status.HTTP_400_BAD_REQUEST)
    
    if not validate_student_id(student_id):
        return Response({"error": "Invalid student ID format. Expected format: XX-X-XX-XX-XXXXXX (e.g., CS-A-21-02-123456)"}, status=status.HTTP_400_BAD_REQUEST)

    if ans1 == item.mcq_1_answer_correct and ans2 == item.mcq_2_answer_correct:
        otp = generate_otp()
        item.claim_code = otp
        item.status = 'Claimed'
        item.save()
        Claim.objects.create(
            lost_item=item,
            student_id=student_id,
            answer_1=ans1,
            answer_2=ans2,
            otp_code=otp,
            is_verified=True
        )
        return Response({"otp_code": otp, "message": "Verification successful, Use this OTP to unlock the vault. After using OTP vault will open for 10 seconds."}, status=status.HTTP_200_OK)
    return Response({"error": "Verification failed, answers do not match."}, status=status.HTTP_400_BAD_REQUEST)

@api_view(['POST'])
def verify_otp(request):
    otp = request.data.get('otp_code')
    claim = Claim.objects.filter(otp_code=otp, otp_used=False, is_verified=True).first()

    if claim:
        claim.otp_used = True
        claim.save()
        # Do NOT update item status here; status is updated in verify_user_otp when user collects item
        item = claim.lost_item
        return Response({
            "message": "OTP verified successfully. Vault opened!",
            "open_duration": 10,  # seconds
            "item_name": item.item_name
        }, status=status.HTTP_200_OK)
    return Response({"error": "Invalid or expired OTP."}, status=status.HTTP_400_BAD_REQUEST)


@api_view(['POST'])
def verify_user_otp(request):
    """API endpoint for ESP32 to verify user OTP"""
    otp = request.data.get('otp_code')
    
    if not otp:
        return Response({"error": "OTP code is required."}, status=status.HTTP_400_BAD_REQUEST)
    
    claim = Claim.objects.filter(otp_code=otp, otp_used=False, is_verified=True).first()

    if claim:
        claim.otp_used = True
        claim.save()
        item = claim.lost_item
        item.status = 'Resolved'  # Set to Resolved when user collects item
        item.save()
        return Response({
            "success": True,
            "message": "User OTP verified successfully. Vault opened!",
            "action": "user_collect",
            "item_name": item.item_name,
            "open_duration": 10
        }, status=status.HTTP_200_OK)
    return Response({
        "success": False,
        "error": "Invalid or expired OTP."
    }, status=status.HTTP_400_BAD_REQUEST)


@api_view(['POST'])
def verify_admin_password(request):
    password = request.data.get('password')
    
    if not password:
        return Response({"error": "Password is required."}, status=status.HTTP_400_BAD_REQUEST)
    
    # Get or create vault settings
    vault_settings, created = VaultSettings.objects.get_or_create(
        id=1,
        defaults={'admin_password': '555'}
    )
    
    if password == vault_settings.admin_password:
        return Response({
            "success": True,
            "message": "Admin password verified successfully. Vault opened!",
            "action": "admin_refill",
            "open_duration": 10
        }, status=status.HTTP_200_OK)
    
    return Response({
        "success": False,
        "error": "Invalid admin password."
    }, status=status.HTTP_400_BAD_REQUEST)