#include <string>
#pragma once
using namespace std;

class Produs {
private:
    int id;
    string nume;
    string tip;
    double pret;
public:
    Produs(int id, string nume, string tip, double pret) : id{id}, nume{nume}, tip{tip}, pret{pret} {}
    int getId() const { return id; }
    string getNume() const { return nume; }
    string getTip() const { return tip; }
    double getPret() const { return pret; }
    void setNume(string nume) { this->nume = nume; }
    void setTip(string tip) { this->tip = tip; }
    void setPret(double pret) { this->pret = pret; }
    int get_nr_vocale() const {
        int nr = 0;
        for (auto c : this->nume)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                nr++;
        return nr;
    }

};
