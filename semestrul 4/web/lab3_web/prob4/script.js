document.addEventListener('DOMContentLoaded', function () {
    const tables = document.querySelectorAll('.sortable-table');

    tables.forEach(table => {
      const rows = Array.from(table.rows);
      const headerColumn = rows.map(row => row.cells[0]);

      headerColumn.forEach((cell, rowIndex) => {
        if(rowIndex === 0) return; 
        cell.addEventListener('click', function () {
          sortTableByRow(table, rowIndex);
        });
      });
    });

    const sortStates = new WeakMap();

    function sortTableByRow(table, rowIndex) {
      const rows = Array.from(table.rows);
      const header = rows[0].cells.length; // extrgem numărul de coloane
      //data contine referinta la numarul coloanei
      const data = [];

      for (let col = 1; col < header; col++) {
        const colData = {
          index: col,
          value: rows[rowIndex].cells[col].textContent
        };
        data.push(colData);
      }

      // verificăm dacă am mai sortat acest tabel și rând
      let currentState = sortStates.get(table) || {};
      let ascending = !(currentState.rowIndex === rowIndex && currentState.ascending);

      // sortăm alfabetic sau numeric
      const isNumeric = data.every(item => !isNaN(item.value));
      data.sort((a, b) => {
        let valA = isNumeric ? parseFloat(a.value) : a.value.toLowerCase();
        let valB = isNumeric ? parseFloat(b.value) : b.value.toLowerCase();

        if (valA < valB) return ascending ? -1 : 1;
        if (valA > valB) return ascending ? 1 : -1;
        return 0;
      });

      // rearanjăm celulele din fiecare rând, în funcție de sortarea de mai sus
      for (let row of rows) {
        const fixed = row.cells[0]; // antetul
        const sortedCells = data.map(d => row.cells[d.index]);
        while (row.cells.length > 1) {
          row.deleteCell(1);
        }
        sortedCells.forEach(cell => row.appendChild(cell));
      }

      // salvăm starea de sortare
      sortStates.set(table, { rowIndex, ascending });
    }
  });