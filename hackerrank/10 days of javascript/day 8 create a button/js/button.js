function incrementButton(event) {
    event.target.innerHTML = +event.target.innerHTML + 1;
}

let button = document.getElementById('btn');
button.addEventListener('click', incrementButton, false);