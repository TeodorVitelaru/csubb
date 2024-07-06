
#include "Repo.h"
#include "Errors.h"
#include <fstream>


void Repo::load_from_file()
{
    ifstream f(filename);
    if (!f.is_open())
        throw Exception("The file could not be opened!");
    while (!f.eof())
    {
       int id;
       string nume;
       string tip;
       double pret;
       if (f.eof()) break;
       f >> id;
       if (f.eof()) break;
       f >> nume;
       if (f.eof()) break;
       f >> tip;
       if (f.eof()) break;
       f >> pret;
       Produs p{id, nume, tip, pret};
       Repo::store(p);
    }
}


void Repo::write_to_file() {
    ofstream f(filename);
    if (!f.is_open())
        throw Exception("The file could not be opened!");
    for (const Produs &p : this->get_all())
    {
        f << p.getId() << endl;
        f << p.getNume() << endl;
        f << p.getTip() << endl;
        f << p.getPret() << endl;
    }
}

void Repo::store(const Produs &prod) {
    if(exists(prod.getId()))
        throw Exception("The product already exists!");
    this->produse.push_back(prod);
    write_to_file();

}


bool Repo::exists(int id) {
    for (Produs &p : this->produse)
        if (p.getId() == id)
            return true;
    return false;
}