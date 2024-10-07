from django.shortcuts import render,redirect
from .forms import DepositeForm
from .models import Transaction
from .constants import TRANSACTION_TYPE, DEPOSITE, BORROW, RETURN
from django.views.generic import CreateView
from django.contrib import messages
from django.urls import reverse_lazy
from django.contrib.auth.mixins import LoginRequiredMixin
from Books.models import Book
from UserAccounts.models import UserLibraryAccount
from django.contrib.auth.decorators import login_required
# Create your views here.

class TransactionCreateMixin(LoginRequiredMixin, CreateView):

    template_name = 'transaction_form.html'
    model = Transaction
    title = ''
    success_url = reverse_lazy('profile')

    def get_form_kwargs(self):
        kwargs = super().get_form_kwargs()
        kwargs.update(
            {
                'account' : self.request.user.account,
            }
        )
        return kwargs
    
    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context.update({
            'title': self.title,
        })
        return context
    

class DepositeMoneyView(TransactionCreateMixin):
    form_class = DepositeForm
    title = 'Deposite Money'

    def get_initial(self):
        initial = {'transaction_type': DEPOSITE }
        return initial
    
    def form_valid(self, form):
        amount = form.cleaned_data.get('amount')
        account = self.request.user.account
        account.balance += amount

        account.save( update_fields = ['balance'])

        messages.success(self.request, f'{amount} tk is deposited successfully in your account')
        return super().form_valid(form)
    
@login_required
def borrow_view(request,id):
    user = request.user
    user_account = UserLibraryAccount.objects.filter(user=user).first()
    book = Book.objects.get(id=id)

    if book.price > user_account.balance:
        messages.error(request,'You do not have enough Money')
        return redirect('homepage')
    else:
        user_account.balance -= book.price
        user_account.save()

        Transaction.objects.create(
            account = user_account,
            amount = book.price,
            balance_after_transaction = user_account.balance,
            transaction_type = BORROW
        )

        messages.success(request,'Book borrowed successfully')
        book.borrowing_users.add(user)


@login_required
def return_view(request,id):
    user = request.user
    user_account = UserLibraryAccount.objects.filter(user=user).first()
    book = Book.objects.get(id=id)

    user_account.balance += book.price
    user_account.save()

    Transaction.objects.create(
        account = user_account,
        amount = book.price,
        balance_after_transaction = user_account.balance,
        transaction_type = RETURN
    )

    book.borrowing_users.remove(user)
    messages.success(request,'Book returned successfully')
    return redirect('profile')