from django.urls import path
from .views import ProductDetailView, add_to_cart, update_cart, remove_from_cart, cart_detail

urlpatterns = [
    path('product/<int:id>/', ProductDetailView.as_view(), name='product_details'),
    path('add_to_cart/<int:product_id>/', add_to_cart, name='add_to_cart'),
    path('update_cart/<int:product_id>/<str:action>/', update_cart, name='update_cart'),
    path('remove_from_cart/<int:product_id>/', remove_from_cart, name='remove_from_cart'),
    path('cart/', cart_detail, name='cart_detail'),
]