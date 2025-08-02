from django.shortcuts import render, redirect,get_object_or_404
from .models import LostItem
from .utils import shuffle_options

# Create your views here.
def home(request):
    unclaimed_items = LostItem.objects.filter(status='Unclaimed')
    claimed_items = LostItem.objects.filter(status='Claimed')
    # resolved_items are not shown anymore
    return render(request, 'home.html', {
        'unclaimed_items': unclaimed_items,
        'claimed_items': claimed_items
    })

def post_item(request):
    if request.method == 'POST':
        item_name = request.POST.get('item_name')
        description = request.POST.get('description')

        mcq_1_question = request.POST.get('mcq_1_question')
        mcq_1_answer_correct = request.POST.get('mcq_1_answer_correct')
        mcq_1_answer_incorrect_1 = request.POST.get('mcq_1_answer_incorrect_1')
        mcq_1_answer_incorrect_2 = request.POST.get('mcq_1_answer_incorrect_2')
        mcq_1_answer_incorrect_3 = request.POST.get('mcq_1_answer_incorrect_3')

        mcq_2_question = request.POST.get('mcq_2_question')
        mcq_2_answer_correct = request.POST.get('mcq_2_answer_correct')
        mcq_2_answer_incorrect_1 = request.POST.get('mcq_2_answer_incorrect_1')
        mcq_2_answer_incorrect_2 = request.POST.get('mcq_2_answer_incorrect_2')
        mcq_2_answer_incorrect_3 = request.POST.get('mcq_2_answer_incorrect_3')

        lost_item = LostItem.objects.create(
            item_name=item_name,
            description=description,

            mcq_1_question=mcq_1_question,
            mcq_1_answer_correct=mcq_1_answer_correct,
            mcq_1_answer_incorrect_1=mcq_1_answer_incorrect_1,
            mcq_1_answer_incorrect_2=mcq_1_answer_incorrect_2,
            mcq_1_answer_incorrect_3=mcq_1_answer_incorrect_3,

            mcq_2_question=mcq_2_question,
            mcq_2_answer_correct=mcq_2_answer_correct,
            mcq_2_answer_incorrect_1=mcq_2_answer_incorrect_1,
            mcq_2_answer_incorrect_2=mcq_2_answer_incorrect_2,
            mcq_2_answer_incorrect_3=mcq_2_answer_incorrect_3
        )
        return redirect('home')

    return render(request, 'post_item.html')


def claim_item(request, item_id):
    item = get_object_or_404(LostItem, id=item_id)
    mcq_1_options = shuffle_options(item.mcq_1_answer_correct,
                                   item.mcq_1_answer_incorrect_1,
                                   item.mcq_1_answer_incorrect_2,
                                   item.mcq_1_answer_incorrect_3)
    mcq_2_options = shuffle_options(item.mcq_2_answer_correct,
                                   item.mcq_2_answer_incorrect_1,
                                   item.mcq_2_answer_incorrect_2,
                                   item.mcq_2_answer_incorrect_3)
    return render(request, 'claim_item.html', {
        'item': item,
        'mcq_1': {
            'question': item.mcq_1_question,
            'options': mcq_1_options
        },
        'mcq_2': {
            'question': item.mcq_2_question,
            'options': mcq_2_options
        }
    })