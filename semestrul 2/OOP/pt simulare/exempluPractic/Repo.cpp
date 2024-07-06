#include "Repo.h"
#include <fstream>
#include <iostream>
#include "Errors.h"
using namespace std;

void Repo::loadFromFile() {
    ifstream in(filename);
    if(!in.is_open())
        throw Exception("Fisierul "+filename+" nu exista!");
    while(!in.eof())
    {
        int suprafata;
        string strada;
        int pret;
        if(in.eof()) break;
        in>>suprafata;
        if(in.eof()) break;
        in>>strada;
        if(in.eof()) break;
        in>>pret;
        Apartament ap{suprafata, strada, pret};
        Repo::store(ap);
    }
}

void Repo::writeToFile() {
    ofstream out(filename);
    if(!out.is_open())
        throw Exception("Fisierul "+filename+" nu exista!");
    for(auto& ap : apartamente)
    {
        out<<ap.get_suprafata()<<endl;
        out<<ap.get_strada()<<endl;
        out<<ap.get_pret()<<endl;
    }
}

void Repo::del(const Apartament &ap) {
    int i=0;
    while(i<apartamente.size())
    {
        if(apartamente.at(i).get_strada() == ap.get_strada() && apartamente.at(i).get_suprafata() == ap.get_suprafata() && apartamente.at(i).get_pret() == ap.get_pret())
        {
            apartamente.erase(apartamente.begin()+i);
            break;
        }
        i++;
    }
    writeToFile();
}

void Repo::store(const Apartament &ap) {
    for(auto& ap1 : apartamente)
        if(ap1.get_strada() == ap.get_strada() && ap1.get_suprafata() == ap.get_suprafata() && ap1.get_pret() == ap.get_pret())
            throw Exception("Apartamentul exista deja!");
    apartamente.push_back(ap);
    writeToFile();
}


