import random

def generate_otp():
    return str(random.randint(10000, 99999))

def shuffle_options(correct, wrong_1, wrong_2, wrong_3):
    options = [correct, wrong_1, wrong_2, wrong_3]
    random.shuffle(options)
    return options