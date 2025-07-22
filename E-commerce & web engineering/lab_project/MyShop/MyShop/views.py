from django.shortcuts import render
from products.models import Product

def home(request):
    products = Product.objects.all()
    liked_products = request.session.get('liked_products', [])
    return render(request, 'index.html', {'products': products, 'liked_products': liked_products})