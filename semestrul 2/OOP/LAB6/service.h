#include <iostream>
#include "repo.h"
#include "validator.h"

typedef int(*Sort)(const Oferta&, const Oferta&);

class Service
{
private:
    Repo& repo;
    Validator& val;
public:
    /*
     * Constructorul serivce ului
     * oferta_repo: obiect de tip repo
     * val: validatorul
     */
    Service(Repo& oferta_repo, Validator& val) :repo{ oferta_repo }, val{ val }{};

    Service(const Service& ot) = delete;

    /*
     * functie de adaugare a unei oferte
     * denumire: string, denumirea ofertei
     * destinatie: string, destinatia ofertei
     * tip: string, tipul ofertei
     * pret: int, pretul ofertei
     * return: -
     */
    void adaugare_oferta(string denumire, string destinatie, string tip, int pret);

    /*
     * functie de stergere a unei oferte
     * poz: pozitia ofertei care se sterge
     * return: -
     */
    void stergere_oferta(int poz);

    /*
     * Functie de modificare a ofertei
     * denumire: string, denumirea ofertei de modificat
     * destinatie: string, destinatia ofertei de modificat
     * tip: string, tipul noii oferte
     * pret: int, pretul noii oferte
     * return: -
     */
    void modificare_oferta(const string& denumire, const string& destinatie, const string& tip, int pret);

    /*
     * functie de cautare a unei oferte
     * denumire: string, denumirea dupa care se cauta
     * destinatie: string, destinatia dupa care se cauta
     * return: oferta gasita
     */
    Oferta cautare_oferte(const string& denumire, const string& destinatie);

    /*
     * functie de sortare generica
     * (*fct)(const Oferta&, const Oferta&): functie de comparare
     * ord: modul in care se sorteaza
     * return: -
     */
    void sortare_generica(int(*fct)(const Oferta&, const Oferta&), int ord);

    /*
     * functie de filtrare dupa destinatie
     * destinatie: string, destinatia dupa care se filtreaza
     * return: o lista de oferta care au aceeasi destinatie cu cea data
     */
    vector<Oferta> filtrare_destinatie(const string& destinatie);

    /*
     * functie de filtrare dupa pret
     * pret: int, pretul dupa care se filtreaza
     * return: o lista de oferta care au aceeasi destinatie cu cea data
     */
    vector<Oferta> filtrare_pret(const int& pret);

    /*
     * functie de returnare a listei de oferte
     * return: lista de oferte
     */
    const vector<Oferta>& get_all_oferte()
    {
        return this->repo.get_all_oferte();
    }
};
