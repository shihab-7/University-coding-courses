from django.shortcuts import render
from products.models import Product
from users.models import LikedProduct

def home(request):
    products = Product.objects.all()
    liked_products = LikedProduct.objects.filter(user=request.user).select_related('product')
    return render(request, 'index.html', {'products': products, 'liked_products': liked_products})