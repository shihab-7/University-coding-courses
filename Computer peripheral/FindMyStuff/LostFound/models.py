from django.db import models

# Create your models here.
class LostItem(models.Model):
    item_name = models.CharField(max_length=100)
    description = models.TextField(blank=True)
    date_registered = models.DateTimeField(auto_now_add=True)

    mcq_1_question = models.CharField(max_length=200, blank=True)
    mcq_1_answer_correct = models.CharField(max_length=100, blank=True)
    mcq_1_answer_incorrect_1 = models.CharField(max_length=100, blank=True)
    mcq_1_answer_incorrect_2 = models.CharField(max_length=100, blank=True)
    mcq_1_answer_incorrect_3 = models.CharField(max_length=100, blank=True)

    mcq_2_question = models.CharField(max_length=200, blank=True)
    mcq_2_answer_correct = models.CharField(max_length=100, blank=True)
    mcq_2_answer_incorrect_1 = models.CharField(max_length=100, blank=True)
    mcq_2_answer_incorrect_2 = models.CharField(max_length=100, blank=True)
    mcq_2_answer_incorrect_3 = models.CharField(max_length=100, blank=True)

    status = models.CharField(max_length=20, choices=[('Unclaimed', 'Unclaimed'), ('Claimed', 'Claimed'),('Resolved', 'Resolved')], default='Unclaimed')
    claim_code = models.CharField(max_length=6, blank=True,null=True)

    def __str__(self):
        return f"{self.item_name} - {self.status}"
    

class Claim(models.Model):
    lost_item = models.ForeignKey(LostItem, on_delete=models.CASCADE)
    student_id = models.CharField(max_length=100)
    answer_1 = models.CharField(max_length=100, blank=True)
    answer_2 = models.CharField(max_length=100, blank=True)
    is_verified = models.BooleanField(default=False)
    otp_code = models.CharField(max_length=6, blank=True, null=True)
    otp_used = models.BooleanField(default=False)
    date_claimed = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"Claim for {self.lost_item.item_name} by {self.student_id}"


class VaultSettings(models.Model):
    admin_password = models.CharField(max_length=10, default="555")
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    def __str__(self):
        return f"Vault Admin Password"

    class Meta:
        verbose_name = 'Vault Settings'
        verbose_name_plural = 'Vault Settings'