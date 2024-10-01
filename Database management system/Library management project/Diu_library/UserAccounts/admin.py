from django.contrib import admin
from .models import UserLibraryAccount, UserAddresses
# Register your models here.

admin.site.register(UserLibraryAccount)
admin.site.register(UserAddresses)
