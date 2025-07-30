from django.contrib import admin
from .models import UserShopAccount, UserAddress
# Register your models here.
admin.site.register(UserShopAccount)
admin.site.register(UserAddress)
