from django.db import models
from django.contrib.auth.models import User
from Categories.models import Category

# Create your models here.
class Book(models.Model):
    category = models.ManyToManyField(Category)
    title = models.CharField(max_length=100)
    description = models.TextField(max_length=300)
    image = models.ImageField(upload_to='books/', blank=True, null=True)
    borrowing_users = models.ManyToManyField(User, related_name='borrow_history',blank=True)

    def __str__(self) -> str:
        return f'Book Title : {self.title}'