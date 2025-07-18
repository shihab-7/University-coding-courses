from django.urls import path
from .views import report_issue

urlpatterns = [
    path('report/<int:item_id>/', report_issue, name='report_issue'),
]
