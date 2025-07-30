from django.db import models
from django.contrib.auth.models import User
from Categories.models import Category

# Create your models here.
class Product(models.Model):
    category = models.ManyToManyField(Category)
    title = models.CharField(max_length=100)
    description = models.TextField(max_length=300)
    price = models.DecimalField(max_digits=10, decimal_places=2,default=0.00)
    image = models.ImageField(upload_to='products/', blank=True, null=True)
    cart_user = models.ManyToManyField(User, related_name='cart', blank=True)
    launched_date = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'Product name : {self.title}'

class CartItem(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    product = models.ForeignKey(Product, on_delete=models.CASCADE)
    quantity = models.PositiveIntegerField(default=1)
    added_at = models.DateTimeField(auto_now_add=True)

    class Meta:
        unique_together = ('user', 'product')

    def __str__(self):
        return f"{self.user.username} - {self.product.title} ({self.quantity})"