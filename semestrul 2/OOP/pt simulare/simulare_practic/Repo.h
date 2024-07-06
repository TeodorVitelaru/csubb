#pragma once
#include "Elev.h"
#include <vector>

class Repo {
private:
    vector<Elev> elevi;
    string filename;
    void loadFromFile();
    void writeToFile();
public:
    Repo() = default;
    Repo(string filename) : filename{ filename }
    {
        loadFromFile();
    }
    Repo(const Repo& ot) = delete;

    //Returneaza vectorul de elevi
    const vector<Elev>& getElevi(){
        return this->elevi;
    };

    void set_elevi(vector<Elev> elevi2)
    {
        this->elevi = elevi2;
    }

    /*
     * Stocheava elevul in lista
     * el: Elev
     * return: -
     */
    void store(Elev& el);

    /*
     * Sterge elevul din lista
     * el: Elev
     * return: -
     */
    void del(Elev& el);

    /*
     * Returneaza elevul cu numele si scoala data
     * nume: string
     * scoala: string
     * return: Elev
     */
    const Elev& get_elev(string nume, string scoala);

};


