document.getElementById('trimite').addEventListener('click', function () {
    const nume = document.getElementById('nume');
    const dataNasterii = document.getElementById('dataNasterii');
    const varsta = document.getElementById('varsta');
    const email = document.getElementById('email');
    const mesaj = document.getElementById('mesaj');

    let valid = true;
    let campuriInvalide = [];

    // Resetăm stilurile de eroare
    [nume, dataNasterii, varsta, email].forEach(camp => camp.classList.remove('error'));


    // Validare nume
    if (nume.value.trim() === '') {
        valid = false;
        campuriInvalide.push('nume');
        nume.classList.add('error');
    }

    // Validare data nașterii
    if (dataNasterii.value.trim() === '') {
        valid = false;
        campuriInvalide.push('data nașterii');
        dataNasterii.classList.add('error');
    }

    // Validare vârstă
    if (varsta.value.trim() === '' || isNaN(varsta.value) || varsta.value <= 0) {
        valid = false;
        campuriInvalide.push('vârstă');
        varsta.classList.add('error');
    } else if (dataNasterii.value.trim() !== '') {
        // Calculăm vârsta pe baza datei nașterii
        const dataNasteriiDate = new Date(dataNasterii.value);
        const azi = new Date();
        let varstaCalculata = azi.getFullYear() - dataNasteriiDate.getFullYear();
        const lunaCurenta = azi.getMonth();
        const ziCurenta = azi.getDate();

        // Ajustăm vârsta dacă ziua/luna curentă este înainte de ziua/luna nașterii
        if (
            lunaCurenta < dataNasteriiDate.getMonth() ||
            (lunaCurenta === dataNasteriiDate.getMonth() && ziCurenta < dataNasteriiDate.getDate())
        ) {
            varstaCalculata--;
        }

        // Verificăm dacă vârsta introdusă corespunde cu cea calculată
        if (parseInt(varsta.value, 10) !== varstaCalculata) {
            valid = false;
            campuriInvalide.push('vârstă (nu corespunde cu data nașterii)');
            varsta.classList.add('error');
        }
    }


    // Validare email
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (email.value.trim() === '' || !emailRegex.test(email.value)) {
        valid = false;
        campuriInvalide.push('email');
        email.classList.add('error');
    }

    // Afișare mesaj
    if (valid) {
        mesaj.textContent = 'Datele sunt completate corect';
        mesaj.className = 'success';
    } else {
        mesaj.textContent = `Campurile ${campuriInvalide.join(', ')} nu sunt completate corect`;
        mesaj.className = 'error-message';
    }
});