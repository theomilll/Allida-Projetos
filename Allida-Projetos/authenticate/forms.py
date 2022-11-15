from django.contrib.auth.forms import UserCreationForm, UserChangeForm, PasswordChangeForm, PasswordResetForm
from django.contrib.auth.models import User
from django import forms


class SignUpForm(UserCreationForm):
    username = forms.EmailField(label="",
                               max_length=32, help_text="", widget=forms.TextInput(attrs={'class': 'e261_31', 'placeholder': 'Usuário'}))
    first_name = forms.CharField(label="",
                                 max_length=32, widget=forms.TextInput(attrs={'class': 'e261_27', 'placeholder': 'Nome completo'}))
    password1 = forms.CharField(label="", help_text="",
                                max_length=40, widget=forms.PasswordInput(attrs={'class': 'e261_33', 'placeholder': 'Senha'}))
    password2 = forms.CharField(label="", help_text="",
                                max_length=40, widget=forms.PasswordInput(attrs={'class': 'e261_35', 'placeholder': 'Confirmar Senha'}))

    class Meta:
        model = User
        fields = ['username', 'first_name',
                   'password1', 'password2']


class EditProfileForm(UserChangeForm):
    username = forms.CharField(label="Usuario:",
                               max_length=32, help_text="<small id='emailHelp' class='form-text text-muted'>Required. 150 characters or fewer. Letters, digits and @/./+/-/_ only.</small>", widget=forms.TextInput(attrs={'class': 'form-control'}))
    first_name = forms.CharField(label="Primeiro nome:",
                                 max_length=32, widget=forms.TextInput(attrs={'class': 'form-control'}))
    last_name = forms.CharField(label="Sobrenome:",
                                max_length=32, widget=forms.TextInput(attrs={'class': 'form-control'}))
    email = forms.EmailField(label="Email",
                             max_length=50, widget=forms.EmailInput(attrs={'class': 'form-control'}))
    password = forms.CharField(label="Confirmação de senha",
                               max_length=50, widget=forms.PasswordInput(attrs={'class': 'form-control'}))

    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name',
                  'email']


class ChangePasswordForm(PasswordChangeForm):
    old_password = forms.CharField(label="Senha antiga:",
                                   max_length=32, widget=forms.PasswordInput(attrs={'class': 'form-control'}))
    new_password1 = forms.CharField(label="Nova senha:", help_text="<small><ul class='form-text text-muted'><li>Your password can\'t be too similar to your other personal information.</li><li>Your password must contain at least 8 characters.</li><li>Your password can\'t be a commonly used password.</li><li>Your password can\'t be entirely numeric.</li></ul></small>",
                                    max_length=32, widget=forms.PasswordInput(attrs={'class': 'form-control'}))
    new_password2 = forms.CharField(label="Confirme sua nova senha:",
                                    max_length=32, widget=forms.PasswordInput(attrs={'class': 'form-control'}))

    class Meta:
        model = User
