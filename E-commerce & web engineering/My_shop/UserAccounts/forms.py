from django.contrib.auth.forms import UserCreationForm
from django import forms
from django.contrib.auth.models import User
from .constants import GENDER_TYPES
from .models import UserShopAccount, UserAddress


class UserRegistrationForm(UserCreationForm):
    birth_date = forms.DateField(widget=forms.DateInput(attrs={'type':'date'}))
    gender = forms.ChoiceField(choices=GENDER_TYPES)
    street_address = forms.CharField(max_length=100)
    city = forms.CharField(max_length=50)
    post_code = forms.IntegerField()

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
            post_code = self.cleaned_data.get('post_code')
            birth_date = self.cleaned_data.get('birth_date')
            city = self.cleaned_data.get('city')
            street_address = self.cleaned_data.get('street_address')

            UserAddress.objects.create(
                user = new_user,
                street_address= street_address,
                city = city,
                post_code = post_code,
            )

            UserShopAccount.objects.create(
                user=new_user,
                gender = gender,
                birth_date = birth_date,
                account_no = 100+ new_user.id
            )
        
        return new_user
    
