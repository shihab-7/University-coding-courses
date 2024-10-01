from django.shortcuts import render
from django.views.generic import DetailView
from .models import Book
# Create your views here.


class BookDetailView(DetailView):
    model = Book
    pk_url_kwarg = 'id'
    template_name = 'bookDetails.html'
