from django import forms
from .models import LostItem

class LostItemForm(forms.ModelForm):
    class Meta:
        model = LostItem
        fields = [
            'item_name', 'description',
            'mcq_1_question', 'mcq_1_answer_correct',
            'mcq_1_answer_incorrect_1', 'mcq_1_answer_incorrect_2', 'mcq_1_answer_incorrect_3',
            'mcq_2_question', 'mcq_2_answer_correct',
            'mcq_2_answer_incorrect_1', 'mcq_2_answer_incorrect_2', 'mcq_2_answer_incorrect_3'
        ]
        widgets = {
            'item_name': forms.TextInput(attrs={'required': True}),
            'description': forms.Textarea(attrs={'rows': 4, 'cols': 40}),
            'mcq_1_question': forms.TextInput(attrs={'placeholder': 'Enter question 1', 'required': True}),
            'mcq_1_answer_correct': forms.TextInput(attrs={'placeholder': 'Correct answer', 'required': True}),
            'mcq_1_answer_incorrect_1': forms.TextInput(attrs={'placeholder': 'Incorrect answer 1', 'required': True}),
            'mcq_1_answer_incorrect_2': forms.TextInput(attrs={'placeholder': 'Incorrect answer 2', 'required': True}),
            'mcq_1_answer_incorrect_3': forms.TextInput(attrs={'placeholder': 'Incorrect answer 3', 'required': True}),
            'mcq_2_question': forms.TextInput(attrs={'placeholder': 'Enter question 2', 'required': True}),
            'mcq_2_answer_correct': forms.TextInput(attrs={'placeholder': 'Correct answer', 'required': True}),
            'mcq_2_answer_incorrect_1': forms.TextInput(attrs={'placeholder': 'Incorrect answer 1', 'required': True}),
            'mcq_2_answer_incorrect_2': forms.TextInput(attrs={'placeholder': 'Incorrect answer 2', 'required': True}),
            'mcq_2_answer_incorrect_3': forms.TextInput(attrs={'placeholder': 'Incorrect answer 3', 'required': True}),
        }