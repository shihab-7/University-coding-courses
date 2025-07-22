const navbar = document.querySelector(".navbar");
const menuBtn = document.querySelector("#menu-btn");
const slides = document.querySelectorAll(".home .slides-container .slide");
const header = document.querySelector(".header");

let index = 0;
document.addEventListener("DOMContentLoaded",
	function () {
		const hamburger = document.getElementById("hamburger");
		const navbar = document.querySelector(".navbar");

		hamburger.addEventListener("click", function () {
			navbar.classList.toggle("active");
		});
	});

window.addEventListener("scroll", () => {
	navbar.classList.remove("active");
});

function showSlide(nextIndex) {
	slides[index].classList.remove("active");
	index = (nextIndex + slides.length) % slides.length;
	slides[index].classList.add("active");
}

function next() {
	showSlide(index + 1);
}

function prev() {
	showSlide(index - 1);
}

//real time like/unlike functionality
document.addEventListener('DOMContentLoaded', function() {
  document.querySelectorAll('.like-btn').forEach(function(btn) {
    btn.addEventListener('click', function() {
      const productId = btn.getAttribute('data-product-id');
      fetch(`/users/like/${productId}/`, {
        method: 'POST',
        headers: {
          'X-CSRFToken': getCookie('csrftoken'),
          'X-Requested-With': 'XMLHttpRequest'
        }
      })
      .then(response => response.json())
      .then(data => {
        if (data.liked) {
          btn.textContent = 'Unlike';
          btn.setAttribute('data-liked', 'true');
        } else {
          btn.textContent = 'Like';
          btn.setAttribute('data-liked', 'false');
        }
      });
    });
  });
});

function getCookie(name) {
  let cookieValue = null;
  if (document.cookie && document.cookie !== '') {
    const cookies = document.cookie.split(';');
    for (let i = 0; i < cookies.length; i++) {
      const cookie = cookies[i].trim();
      if (cookie.substring(0, name.length + 1) === (name + '=')) {
        cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
        break;
      }
    }
  }
  return cookieValue;
}