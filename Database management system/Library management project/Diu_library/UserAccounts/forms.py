from typing import Any, Mapping
from django.contrib.auth.forms import UserCreationForm
from django import forms
from django.core.files.base import File
from django.db.models.base import Model
from django.forms.utils import ErrorList
from .constants import GENDER_TYPE
from django.contrib.auth.models import User
from .models import UserLibraryAccount, UserAddresses


class UserRegistrationForm(UserCreationForm):
    birth_date = forms.DateField(widget=forms.DateInput(attrs={'type':'date'}))
    gender = forms.ChoiceField(choices=GENDER_TYPE)
    street_address = forms.CharField(max_length=100)
    city = forms.CharField(max_length=50)
    postal_code = forms.IntegerField()

    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name', 'birth_date', 'gender', 'street_address', 'city','email','password1', 'password2']
        widgets = {
                'username': forms.TextInput(attrs={'placeholder': 'Enter a username'}),
                'first_name': forms.TextInput(attrs={'placeholder': 'Enter your first name'}),
                'last_name': forms.TextInput(attrs={'placeholder': 'Enter your last name'}),
                'birth_date': forms.DateInput(attrs={'type': 'date', 'placeholder': 'Enter your birth date'}),
                'gender': forms.Select(attrs={'placeholder': 'Select your gender'}),
                'street_address': forms.TextInput(attrs={'placeholder': 'Enter your street address'}),
                'city': forms.TextInput(attrs={'placeholder': 'Enter your city'}),
                'email': forms.EmailInput(attrs={'placeholder': 'Enter your email address'}),
                'password1': forms.PasswordInput(attrs={'placeholder': 'Enter your password'}),
                'password2': forms.PasswordInput(attrs={'placeholder': 'Confirm your password'}),
                }
    def __init__(self,*args,**kwargs):
        super(UserRegistrationForm, self).__init__(*args,**kwargs)
        for field in self.fields.values():
            field.help_text = None


    def save(self, commit=True):
        new_user = super().save(commit=False)

        if commit==True:
            new_user.save()
            gender = self.cleaned_data.get('gender')
            postal_code = self.cleaned_data.get('postal_code')
            birth_date = self.cleaned_data.get('birth_date')
            city = self.cleaned_data.get('city')
            street_address = self.cleaned_data.get('street_address')

            UserAddresses.objects.create(
                user = new_user,
                street_address= street_address,
                city = city,
                postal_code = postal_code,
            )

            UserLibraryAccount.objects.create(
                user=new_user,
                gender = gender,
                birth_date = birth_date,
                account_no = 100+ new_user.id
            )
        
        return new_user
    


class UserUpdateForm(forms.ModelForm):
    birth_date = forms.DateField(widget=forms.DateInput(attrs={'type':'date'}))
    gender = forms.ChoiceField(choices=GENDER_TYPE)
    street_address = forms.CharField(max_length=100)
    city = forms.CharField(max_length=50)
    postal_code = forms.IntegerField()
    

    class Meta:
        model = User
        fields = ['first_name', 'last_name', 'email']

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        if self.instance:
            try:
                user_account = self.instance.account
                user_address = self.instance.address
            except UserLibraryAccount.DoesNotExist:
                user_account = None
                user_address = None
            
            if user_account:
                self.fields['gender'].initial = user_account.gender
                self.fields['birth_date'].initial = user_account.birth_date
                self.fields['street_address'].initial = user_address.street_address
                self.fields['city'].initial = user_address.city
                self.fields['postal_code'].initial = user_address.postal_code
    
    def save(self, commit=True):
        user = super().save(commit=False)

        if commit:
            user.save()

            user_account, created = UserLibraryAccount.objects.get_or_create(user=user)

            user_address, created = UserAddresses.objects.get_or_create(user=user)

            user_account.gender = self.cleaned_data['gender']
            user_account.birth_date = self.cleaned_data['birth_date']
            user_account.save()

            user_address.street_address = self.cleaned_data['street_address']
            user_address.city = self.cleaned_data['city']
            user_address.postal_code = self.cleaned_data['postal_code']
            user_address.save()

        return user