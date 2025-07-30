from django.shortcuts import render
from Products.models import Product
from Categories.models import Category

def home(request, category_slug=None):
    data = Product.objects.all()
    categories = Category.objects.all()

    if category_slug is not None:
        category = Category.objects.get(slug=category_slug)
        data = Product.objects.filter(category=category)

    return render(request, 'home.html', {'data': data, 'category': categories})