from django.db import models
from .constants import TRANSACTION_TYPE
from UserAccounts.models import UserLibraryAccount
# Create your models here.

class Transaction(models.Model):
    account = models.ForeignKey(UserLibraryAccount, related_name='transactions', on_delete=models.CASCADE)
    amount = models.DecimalField(max_digits=10,decimal_places=2)
    transaction_type = models.IntegerField(choices = TRANSACTION_TYPE, null=True)
    timestamp = models.DateTimeField(auto_now_add=True)
    balance_after_transaction = models.DecimalField(max_digits=10,decimal_places=2)