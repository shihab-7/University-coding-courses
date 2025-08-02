from django.contrib import admin
from .models import LostItem, Claim, VaultSettings
# Register your models here.

@admin.register(LostItem)
class LostItemAdmin(admin.ModelAdmin):
    list_display = ('item_name', 'status', 'date_registered')
    search_fields = ('item_name',)
    list_filter = ('status', 'date_registered')

@admin.register(Claim)
class ClaimAdmin(admin.ModelAdmin):
    list_display = ('lost_item', 'student_id', 'is_verified', 'otp_used', 'date_claimed')
    search_fields = ('student_id','otp_used')
    list_filter = ('is_verified', 'date_claimed')

@admin.register(VaultSettings)
class VaultSettingsAdmin(admin.ModelAdmin):
    list_display = ('admin_password', 'updated_at')
    fields = ('admin_password',)
    
    def has_add_permission(self, request):
        # Only allow one instance
        return not VaultSettings.objects.exists()
    
    def has_delete_permission(self, request, obj=None):
        # Don't allow deletion
        return False