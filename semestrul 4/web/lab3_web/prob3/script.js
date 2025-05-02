// Generăm matricea cu perechi de numere
const numbers = [...Array(8).keys(), ...Array(8).keys()]; // Perechi de numere de la 0 la 7
numbers.sort(() => Math.random() - 0.5); // Amestecăm numerele

const gameBoard = document.getElementById('game-board');
let firstCell = null;
let secondCell = null;
let revealedPairs = 0;

// Creăm celulele tabelului
numbers.forEach((number, index) => {
    const cell = document.createElement('div');
    cell.classList.add('cell');
    cell.dataset.number = number;
    cell.addEventListener('click', handleCellClick);
    gameBoard.appendChild(cell);
});

function handleCellClick(event) {
    const cell = event.target;

    // Dacă celula este deja dezvăluită sau două celule sunt deja selectate, ieșim
    if (cell.classList.contains('revealed') || secondCell) return;

    // Dezvăluim numărul
    cell.textContent = cell.dataset.number;
    cell.classList.add('revealed');

    if (!firstCell) {
        firstCell = cell;
    } else {
        secondCell = cell;

        // Verificăm dacă numerele coincid
        if (firstCell.dataset.number === secondCell.dataset.number) {
            // Pereche găsită
            firstCell = null;
            secondCell = null;
            revealedPairs++;

            // Verificăm dacă jocul s-a terminat
            if (revealedPairs === 4) {
                document.getElementById('status').textContent = 'Felicitări! Ai castigat!';
            }
        } else {
            // Numerele nu coincid, le ascundem după 2 secunde
            setTimeout(() => {
                firstCell.textContent = '';
                firstCell.classList.remove('revealed');
                secondCell.textContent = '';
                secondCell.classList.remove('revealed');
                firstCell = null;
                secondCell = null;
            }, 2000);
        }
    }
}