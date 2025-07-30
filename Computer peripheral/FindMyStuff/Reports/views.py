from django.shortcuts import render,redirect,get_object_or_404
from .forms import ReportForm
from .models import Report
from LostFound.models import LostItem

# Create your views here.

def report_issue(request, item_id):
    item = get_object_or_404(LostItem, id=item_id)
    
    if request.method == 'POST':
        form = ReportForm(request.POST)
        if form.is_valid():
            report = form.save(commit=False)
            report.lost_item = item
            report.save()
            return redirect('home')
    else:
        form = ReportForm()
    return render(request, 'report.html', {'form': form, 'item': item})