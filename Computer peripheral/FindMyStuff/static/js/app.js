// Student ID validation function
function validateStudentId(studentId) {
    const pattern = /^[A-Z]{2}-[A-Z]-\d{2}-\d{2}-\d{6}$/;
    return pattern.test(studentId);
}

document.getElementById('student_id').addEventListener('input', function(e) {
    const studentId = e.target.value;
    const isValid = validateStudentId(studentId);
    
    if (studentId.length > 0) {
        if (isValid) {
            e.target.style.borderColor = '#28a745';
            e.target.style.backgroundColor = '#f8fff9';
        } else {
            e.target.style.borderColor = '#dc3545';
            e.target.style.backgroundColor = '#fff8f8';
        }
    } else {
        e.target.style.borderColor = '#ddd';
        e.target.style.backgroundColor = 'white';
    }
});

document.getElementById('claimForm').addEventListener('submit', function(e) {
    e.preventDefault();
    
    const studentId = document.getElementById('student_id').value;
    
    // Validate student ID before sending
    if (!validateStudentId(studentId)) {
        const messageDiv = document.getElementById('result-message');
        messageDiv.style.display = 'block';
        messageDiv.style.background = '#f8d7da';
        messageDiv.style.color = '#721c24';
        messageDiv.innerHTML = `
            <h3>Invalid Student ID Format</h3>
            <p>Please enter a valid student ID in the format: XX-X-XX-XX-XXXXXX</p>
            <p>Example: CS-A-21-02-123456</p>
        `;
        return;
    }
    
    const formData = new FormData(this);
    const data = {
        student_id: studentId,
        answer_1: formData.get('answer_1'),
        answer_2: formData.get('answer_2')
    };
    
    // Get CSRF token
    const csrfToken = document.querySelector('[name=csrfmiddlewaretoken]').value;
    
    fetch(`/api/verify-mcq/${window.itemId}/`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'X-CSRFToken': csrfToken
        },
        body: JSON.stringify(data)
    })
    .then(response => response.json())
    .then(result => {
        const messageDiv = document.getElementById('result-message');
        messageDiv.style.display = 'block';
        
        if (result.otp_code) {
            messageDiv.style.background = '#d4edda';
            messageDiv.style.color = '#155724';
            messageDiv.innerHTML = `
                <h3>Verification Successful!</h3>
                <p><strong>Your OTP Code: ${result.otp_code}</strong></p>
                <p>${result.message}</p>
                <p style="margin-top: 15px; font-weight: bold;">Go to the university vault and enter this code on the numeric pad.</p>
                <p id="countdown" style="margin-top: 15px; color: #155724;">You will be redirected to home in <span id="count">20</span> seconds.</p>
            `;
            document.getElementById('verification-form').style.display = 'none';
            // show countdown
            let count = 20;
            const countSpan = document.getElementById('count');
            const timer = setInterval(function() {
                count--;
                countSpan.textContent = count;
                if (count <= 0) {
                    clearInterval(timer);
                    window.location.href = '/';
                }
            }, 1000);
        } else {
            messageDiv.style.background = '#f8d7da';
            messageDiv.style.color = '#721c24';
            messageDiv.innerHTML = `
                <h3>Verification Failed</h3>
                <p>${result.error}</p>
                <p>Please check your answers and try again.</p>
            `;
        }
    })
    .catch(error => {
        console.error('Error:', error);
        const messageDiv = document.getElementById('result-message');
        messageDiv.style.display = 'block';
        messageDiv.style.background = '#f8d7da';
        messageDiv.style.color = '#721c24';
        messageDiv.innerHTML = '<p>An error occurred. Please try again.</p>';
    });
});