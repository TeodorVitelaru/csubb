#pragma once

//Functie void care afisaza meniul principal
void print_menu();

//Functie void care afiseaza meniul pentru sortare oferte;
void sub_menu_sort_offerts();

//Functie void care afiseaza submeniul pentru filtru tip(oferte);
void sub_menu_filter_tip_offerts();

//Functia digits primeste ca parametru un numar natural n;
//Functia returneaza cate cifre are numarul n;
int digits(int nr);

//Functie void care primeste ca parametru un array de oferte si dimensiunea array
//Scopul functiei este de a afisa tabelar informatiile pentru fiecare oferta;
void display_oferte_by_array(Vector vec);

//Functie void care primeste ca parametru o adresa catre o zona de memorie, si acolo se citeste o linie integral!
void read_line(char* store);

//Functia run console primeste ca argument un struct controller* din functia main princiapala a programului
//Aici se interactioneaza cu utilizatorul->se citeste date si se afiseaza erorile in caz de date introduse gresit!
void run_console(Controller controller);