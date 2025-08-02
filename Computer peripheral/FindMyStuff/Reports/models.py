from django.db import models
from LostFound.models import LostItem
# Create your models here.

class Report(models.Model):
    lost_item = models.ForeignKey(LostItem, on_delete=models.CASCADE)
    email = models.EmailField(null=True, blank=True)
    phone_number = models.CharField(max_length=15, blank=True)
    report_date = models.DateTimeField(auto_now_add=True)
    issue_text = models.TextField()


    def __str__(self):
        return f"Report for {self.lost_item.item_name} on {self.report_date.strftime('%Y-%m-%d %H:%M:%S')}"

    class Meta:
        verbose_name = 'Report'
        verbose_name_plural = 'Reports'