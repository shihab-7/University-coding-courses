from django.urls import path
from . import views, api_views

urlpatterns = [
    path('', views.home, name='home'),
    path('post_item/', views.post_item, name='post_item'),
    path('claim_item/<int:item_id>/', views.claim_item, name='claim_item'),
    path('api/verify-mcq/<int:item_id>/', api_views.verify_mcq, name='verify_mcq'),
    path('api/verify-otp/', api_views.verify_otp, name='verify_otp'),
]
