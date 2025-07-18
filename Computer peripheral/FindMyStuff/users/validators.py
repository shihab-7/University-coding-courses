import re

def validate_student_id(student_id):
    pattern = r'^[A-Z]{2}-[A-Z]-\d{2}-\d{2}-\d{6}$'
    return re.match(pattern, student_id) is not None