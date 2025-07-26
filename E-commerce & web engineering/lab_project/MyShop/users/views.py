from django.views.decorators.http import require_POST
from .models import Cart, CartItem
from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.contrib.auth.decorators import login_required
from django.contrib import messages
from .models import UserProfile, LikedProduct
from products.models import Product

def register_view(request):
    if request.method == 'POST':
        form = UserCreationForm(request.POST)
        if form.is_valid():
            user = form.save()
            UserProfile.objects.create(user=user)
            messages.success(request, 'Registration successful!')
            return redirect('login')
    else:
        form = UserCreationForm()
    return render(request, 'registration.html', {'form': form})

def login_view(request):
    if request.method == 'POST':
        form = AuthenticationForm(request, data=request.POST)
        if form.is_valid():
            user = form.get_user()
            login(request, user)
            return redirect('profile')
    else:
        form = AuthenticationForm()
    return render(request, 'login.html', {'form': form})

@login_required
def logout_view(request):
    logout(request)
    return redirect('home')

@login_required
def profile_view(request):
    user_profile, created = UserProfile.objects.get_or_create(user=request.user)
    liked_products = LikedProduct.objects.filter(user=request.user).select_related('product')
    return render(request, 'profile.html', {
        'user_profile': user_profile,
        'liked_products': [lp.product for lp in liked_products],
    })

@login_required
def cart_view(request):
    cart, created = Cart.objects.get_or_create(user=request.user)
    cart_items = CartItem.objects.filter(cart=cart).select_related('product')
    cart_total = sum(item.product.price * item.quantity for item in cart_items)
    return render(request, 'cart.html', {
        'cart_items': cart_items,
        'cart_total': cart_total,
    })
@login_required
@require_POST
def add_to_cart(request, product_id):
    product = Product.objects.get(id=product_id)
    cart, created = Cart.objects.get_or_create(user=request.user)
    cart_item, created = CartItem.objects.get_or_create(cart=cart, product=product)
    if not created:
        cart_item.quantity += 1
        cart_item.save()
    return redirect(request.META.get('HTTP_REFERER', 'cart'))

@login_required
@require_POST
def remove_from_cart(request, product_id):
    cart = Cart.objects.get(user=request.user)
    try:
        cart_item = CartItem.objects.get(cart=cart, product_id=product_id)
        if cart_item.quantity > 1:
            cart_item.quantity -= 1
            cart_item.save()
        else:
            cart_item.delete()
    except CartItem.DoesNotExist:
        pass
    return redirect('cart')

@login_required
def toggle_like_product(request, product_id):
    product = Product.objects.get(id=product_id)
    liked, created = LikedProduct.objects.get_or_create(user=request.user, product=product)
    if not created:
        liked.delete()
    # Instead of redirect, return to the previous page using JavaScript if AJAX, or simply reload if not
    if request.headers.get('x-requested-with') == 'XMLHttpRequest':
        # For AJAX requests, return a simple response
        from django.http import JsonResponse
        return JsonResponse({'liked': created})
    # For normal requests, reload the previous page
    return redirect(request.META.get('HTTP_REFERER', 'profile'))

