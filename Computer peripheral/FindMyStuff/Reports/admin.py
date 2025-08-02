from django.contrib import admin
from .models import Report
from .forms import ReportAdminForm


class ReportAdmin(admin.ModelAdmin):
    form = ReportAdminForm
    list_display = ('lost_item', 'email', 'phone_number', 'report_date', 'issue_text', 'get_status')
    search_fields = ('lost_item__item_name',)
    ordering = ('-report_date',)

    def get_status(self, obj):
        return obj.lost_item.status

admin.site.register(Report, ReportAdmin)