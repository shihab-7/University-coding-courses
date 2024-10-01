from django.urls import path
from .views import BookDetailView

urlpatterns = [
    path('details/<int:id>/', BookDetailView.as_view(), name='Book_Details')
]
