from django.contrib import admin
from .models import Product

class ProductAdmin(admin.ModelAdmin):
    list_display = ('name', 'price', 'stock', 'is_active', 'created_at')
    list_filter = ('is_active', 'category')
    search_fields = ('name', 'description')

admin.site.register(Product, ProductAdmin)
