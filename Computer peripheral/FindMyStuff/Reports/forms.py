from django import forms
from .models import Report

class ReportForm(forms.ModelForm):
    class Meta:
        model = Report
        fields = ['issue_text', 'email', 'phone_number']


class ReportAdminForm(forms.ModelForm):
    status = forms.ChoiceField(choices=[('Unclaimed', 'Unclaimed'), ('Claimed', 'Claimed'), ('Resolved', 'Resolved')])

    class Meta:
        model = Report
        fields = '__all__'

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        if self.instance and self.instance.lost_item:
            self.fields['status'].initial = self.instance.lost_item.status

    def save(self, commit=True):
        instance = super().save(commit=False)
        if 'status' in self.cleaned_data:
            instance.lost_item.status = self.cleaned_data['status']
            instance.lost_item.save()
        if commit:
            instance.save()
        return instance