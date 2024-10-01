from django.shortcuts import render
from django.views.generic import FormView
from .forms import  UserRegistrationForm
from django.urls import reverse_lazy
from django.contrib.auth import login
from django.contrib.auth.views import LoginView,LogoutView
from django.utils.decorators import method_decorator
from django.contrib.auth.decorators import login_required
from django.views import View
from Books.models import Book
from Borrows.models import Transaction
from Borrows.constants import BORROW


# Create your views here.
class UserRegistrationView(FormView):
    template_name = 'user_registration.html'
    form_class = UserRegistrationForm
    success_url = reverse_lazy('homepage')
    # print('error')
    def form_valid(self, form):
        user = form.save()
        login(self.request, user)
        return super().form_valid(form)
    

class UserLoginView(LoginView):
    template_name = 'user_login.html'
    def get_success_url(self):
        return reverse_lazy('homepage')

@method_decorator(login_required, name='dispatch')
class UserLogoutView(LogoutView):
    def get_success_url(self):
        return reverse_lazy('profile')

@method_decorator(login_required, name='dispatch')
class UserProfileView(View):
    template_name = 'profile.html'

    def get(self, request, *args, **kwargs):
        borrowed_books = Book.objects.filter(borrowing_users=request.user)

        book_details = []

        for book in borrowed_books:
            each_detail = Transaction.objects.filter(
                account=request.user.account,
                amount = book.price,
                transaction_type = BORROW
            )
            history = {'book': book,'each_detail':each_detail}
            book_details.append(history)
        
        return render(request, self.template_name,{'user':request.user,'book_details':book_details})
    