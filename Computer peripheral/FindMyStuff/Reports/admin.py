from django.contrib import admin
from .models import Report

# Register your models here.
class ReportAdmin(admin.ModelAdmin):
    list_display = ('lost_item', 'report_date')
    search_fields = ('lost_item__item_name',)
    ordering = ('-report_date',)
