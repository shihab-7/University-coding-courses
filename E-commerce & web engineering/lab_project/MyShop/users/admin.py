
# Register your models here.

from django.contrib import admin
from .models import UserProfile, LikedProduct, Cart, CartItem

admin.site.register(UserProfile)
admin.site.register(LikedProduct)
admin.site.register(Cart)
admin.site.register(CartItem)
