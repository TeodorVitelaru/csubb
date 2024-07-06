#include "Repo.h"
#include "Validare.h"
#include "Observer.h"
#pragma once
class Service : public Observable{
private:
    Repo& repo;
    Validator& val;
public:
    /*
     * Constructor
     * @param repo - repository
     * @param val - validator
     */
    Service(Repo& repo, Validator& val) : repo{repo}, val{val} {};
    Service(const Service& ot) = delete;

    /*
     * Functie care adauga o parcare in lista de parcari
     * @param id - int
     * @param adresa - string
     * @param linii - int
     * @param coloane - int
     * @param stare - string
     * @return - -
     * @throw - ValidationException
     */
    void adaugare(int id, string adresa, int linii, int coloane, string stare);

    /*
     * Functie care modifica o parcare din lista de parcari
     * @param id - int
     * @param adresa - string
     * @param linii - int
     * @param coloane - int
     * @param stare - string
     * @return - -
     * @throw - ValidationException
     */
    void modificare(int id, string adresa, int linii, int coloane, string stare);

    /*
     * Functia care returneaza lista de parcari
     * @return vector<Parcare> - vector de parcari
     */
    vector<Parcare>& get_all();

    /*
     * functia care sorteaza parcariile dupa locuri
     * @return vector<Parcare> - vector de parcari
     */
    vector<Parcare> sortare();

    /*
     * Functia care returneaza un string random de caractere X si -
     * @param linii - int
     * @param col - int
     * @return string - string de caractere X si - de lungime linii*col
     */
    string aleator(int linii, int col);

    const Parcare& cauta(int id) const
    {
        for(auto& p : repo.get_all())
        {
            if(p.get_id() == id)
                return p;
        }
        throw Exception("Parcarea nu exista!");
    }

};


