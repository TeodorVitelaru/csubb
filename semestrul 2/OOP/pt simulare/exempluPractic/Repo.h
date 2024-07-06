#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Apartament.h"

class Repo {
private:
    string filename;
    vector<Apartament> apartamente;
    void loadFromFile();
    void writeToFile();
public:
    Repo() = default;
    Repo(string filename) : filename{filename}{
        loadFromFile();
    }; //constructor

    Repo(const Repo& ot) = delete;

    /*
     * functie de stocare a unui apartament
     * ap: apartamentul care se stocheaza
     * return: -
     */
    void store(const Apartament& ap);


    /*
     * functie de stergere a unui apartament
     * ap: apartamentul care se sterge
     * return: -
     */
    void del(const Apartament& ap);

    const vector<Apartament>& get_all()
    {
        return this->apartamente;
    }




};



