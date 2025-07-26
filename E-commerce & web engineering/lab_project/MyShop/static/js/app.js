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

// AJAX like/unlike for product cards
document.addEventListener('DOMContentLoaded', function() {
  document.querySelectorAll('.like-btn').forEach(function(btn) {
    btn.addEventListener('click', function(e) {
      e.preventDefault();
      var form = btn.closest('form');
      var url = form.action;
      var csrftoken = form.querySelector('[name=csrfmiddlewaretoken]').value;
      fetch(url, {
        method: 'POST',
        headers: {
          'X-Requested-With': 'XMLHttpRequest',
          'X-CSRFToken': csrftoken,
        },
      })
      .then(response => response.json())
      .then(data => {
        if (data.liked) {
          btn.innerText = 'Unlike';
          btn.setAttribute('title', 'Unlike');
          btn.classList.add('liked');
        } else {
          btn.innerText = 'Like';
          btn.setAttribute('title', 'Like');
          btn.classList.remove('liked');
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