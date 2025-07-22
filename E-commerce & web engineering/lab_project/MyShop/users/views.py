
# Create your views here.

from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.contrib.auth.decorators import login_required
from django.contrib import messages
from .models import UserProfile, LikedProduct
from products.models import Product

def register_view(request):
    if request.method == 'POST':
        form = UserCreationForm(request.POST)
        if form.is_valid():
            user = form.save()
            UserProfile.objects.create(user=user)
            messages.success(request, 'Registration successful!')
            return redirect('login')
    else:
        form = UserCreationForm()
    return render(request, 'users/register.html', {'form': form})

def login_view(request):
    if request.method == 'POST':
        form = AuthenticationForm(request, data=request.POST)
        if form.is_valid():
            user = form.get_user()
            login(request, user)
            return redirect('profile')
    else:
        form = AuthenticationForm()
    return render(request, 'users/login.html', {'form': form})

def logout_view(request):
    logout(request)
    return redirect('login')

@login_required
def profile_view(request):
    user_profile = UserProfile.objects.get(user=request.user)
    liked_products = LikedProduct.objects.filter(user=request.user).select_related('product')
    all_products = Product.objects.all()
    return render(request, 'users/profile.html', {
        'user_profile': user_profile,
        'liked_products': [lp.product for lp in liked_products],
        'all_products': all_products,
    })

@login_required
def toggle_like_product(request, product_id):
    product = Product.objects.get(id=product_id)
    liked, created = LikedProduct.objects.get_or_create(user=request.user, product=product)
    if not created:
        liked.delete()
    # Instead of redirect, return to the previous page using JavaScript if AJAX, or simply reload if not
    if request.headers.get('x-requested-with') == 'XMLHttpRequest':
        # For AJAX requests, return a simple response
        from django.http import JsonResponse
        return JsonResponse({'liked': created})
    # For normal requests, reload the previous page
    return render(request, 'users/empty_response.html')
