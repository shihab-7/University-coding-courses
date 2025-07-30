from django.db import models
from django.contrib.auth.models import User
from .constants import GENDER_TYPES
# Create your models here.

class UserShopAccount(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE, related_name='account')
    account_no = models.IntegerField(unique=True)
    gender = models.CharField(max_length=10, choices=GENDER_TYPES)
    birth_date = models.DateField(null=True, blank=True)

    def __str__(self):
        return f'User Account: {self.account_no} - {self.user.username}'
    

class UserAddress(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE, related_name='address')
    street_address = models.CharField(max_length=255)
    city = models.CharField(max_length=100)
    post_code = models.IntegerField()

    def __str__(self):
        return f'{self.user.username} from {self.street_address}'
    
