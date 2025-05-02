
document.addEventListener('DOMContentLoaded', () => {
    const carousel = document.querySelector('.carousel');
    const items = carousel.querySelectorAll('li');
    const prevButton = document.getElementById('prev');
    const nextButton = document.getElementById('next');
    let currentIndex = 0;
    const intervalTime = 3000; // n secunde (3 secunde în acest caz)
    let interval;

    // Funcție pentru a afișa un element
    function showItem(index) {
        items.forEach((item, i) => {
            item.classList.toggle('visible', i === index);
        });
    }

    // Funcție pentru a trece la următorul element
    function nextItem() {
        currentIndex = (currentIndex + 1) % items.length;
        showItem(currentIndex);
    }

    // Funcție pentru a trece la elementul anterior
    function prevItem() {
        currentIndex = (currentIndex - 1) % items.length;
        showItem(currentIndex);
    }

    // Evenimente pentru butoane
    nextButton.addEventListener('click', () => {
        clearInterval(interval); // Resetăm intervalul
        nextItem();
        startCarousel();
    });

    prevButton.addEventListener('click', () => {
        clearInterval(interval); // Resetăm intervalul
        prevItem();
        startCarousel();
        
    });

    // Pornim carouselul automat
    function startCarousel() {
        interval = setInterval(nextItem, intervalTime);
    }

    // Inițializare
    showItem(currentIndex);
    startCarousel();
});