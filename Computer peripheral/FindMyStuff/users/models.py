from django.db import models

# Create your models here.
class Student(models.Model):
    student_id = models.CharField(max_length=20, unique=True)
    
    def __str__(self):
        return f"{self.student_id}"
    
    class Meta:
        verbose_name = 'Student'
        verbose_name_plural = 'Students'