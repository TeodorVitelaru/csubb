#include "utils.h"
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include "Vectorul_meu/vector.h"
using namespace std;

#ifndef LAB6_REPO_H
#define LAB6_REPO_H

typedef Oferta ElemType;

class Repo
{
private:
    VectorulMeu<Oferta> allOferte;
    friend class Service;
public:
    Repo() = default;
    Repo(const Repo& ot) = delete;

    /*
     * Functia de stoare a ofertei
     * oferta: oferta care se stocheaza
     * return: -
     */
    void store(const Oferta& oferta);

    /*
     * Functia de sterfere a ofertei
     * poz: pozitia ofertei ce urmeaza a fi stearsa
     * return: -
     */
    void del(const int& poz);

    /*
     * Functia de modificare a ofertei
     * oferta: oferta cu care se modifica
     * return: -
     */
    void modify(const Oferta& oferta);

    /*
     * functia de returnare a ofertelor
     * return: lista de oferte
     */
    const VectorulMeu<Oferta>& get_all_oferte() const;

    /*
     * functia de cautare a unei oferte
     * denumire: denumirea dupa care se cauta
     * destinatie: destinatia dupa care se cauta
     * return: oferta gasita
     */
    const Oferta& find(string denumire, string destinatie);

    /*
     * functie de verificare daca exista o oferta
     * oferta: oferta care se cauta
     * return: true sau false
     */
    bool exists(const Oferta& oferta);

};

/*
 * clasa de exceptii pt repo
 */
class RepoException
{
private:
    string errorMsg;
public:
    RepoException(string errorMsg) :errorMsg{ errorMsg } {};
    string getErrorMessage()
    {
        return this->errorMsg;
    }
};


#endif //LAB6_REPO_H
