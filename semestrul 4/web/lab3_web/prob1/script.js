function mutaElement(sursa, destinatie) {
    const optiuniSelectate = Array.from(sursa.selectedOptions);
    optiuniSelectate.forEach(option => {
      destinatie.appendChild(option);
    });
  }

  /*
  document.getElementById('lista1').ondblclick = function () {
    mutaElement(this, document.getElementById('lista2'));
  };
*/

  const lista1 = document.getElementById('lista1');
  lista1.addEventListener('click', function () {
    mutaElement(this, document.getElementById('lista2'));
  });

  document.getElementById('lista2').ondblclick = function () {
    mutaElement(this, document.getElementById('lista1'));
  };