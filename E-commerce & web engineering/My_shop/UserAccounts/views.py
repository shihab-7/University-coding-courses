from django.shortcuts import render
from django.views.generic import FormView
from .forms import UserRegistrationForm
from django.urls import reverse_lazy
from django.contrib.auth import login
from django.contrib.auth.views import LoginView, LogoutView
from django.contrib.auth.decorators import login_required
from django.views import View
from Products.models import Product
from django.utils.decorators import method_decorator
from Products.models import CartItem

# Create your views here.
class UserRegistrationView(FormView):
    template_name = 'registration.html'
    form_class = UserRegistrationForm
    success_url = reverse_lazy('home')

    def form_valid(self, form):
        user = form.save()
        login(self.request, user)
        return super().form_valid(form)
    
class UserLoginView(LoginView):
    template_name = 'login.html'
    def get_success_url(self):
        return reverse_lazy('profile')

@method_decorator(login_required, name='dispatch')
class UserLogoutView(LogoutView):
    next_page = reverse_lazy('home')

@method_decorator(login_required, name='dispatch')
class UserProfileView(View):
    template_name = 'profile.html'

    def get(self, request, *args, **kwargs):
        cart_items = CartItem.objects.filter(user=request.user)
        return render(request, self.template_name, {'cart_items': cart_items})
