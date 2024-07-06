#include <string>
#include <iostream>
using namespace std;

class Oferta
{
private:
    string denumire{ "" };
    string destinatie{ "" };
    string tip{ "" };
    int pret{ 0 };
public:
    Oferta() = delete;
    /*
     * Constructorul clasei produs
     * denumire, denumirea produsului
     * destinatia, destinatia ofertei
     * tip, tipul ofertei
     * pret, pretul ofertei
     */
    Oferta(string denumire, string destinatie, string tip, int pret) :denumire{ denumire }, destinatie{ destinatie }, tip{ tip }, pret{ pret }{};

    Oferta(const Oferta& ot)
    {
        denumire = ot.denumire;
        destinatie = ot.destinatie;
        tip = ot.tip;
        pret = ot.pret;
    }

    /*
     * Functiile de get pentru fiecare parametru
     * al produsului
     */
    string get_denumire() const;
    string get_destinatie() const;
    string get_tip() const;
    int get_pret() const;

    /*
     * Functiile de set pentru fiecare parametru
     * al produsului
     */
    void set_denumire(string _denumire);
    void set_destinatie(string _destinatie);
    void set_tip(string _tip);
    void set_pret(int _pret);

    /*
     * Functie pentru afisare a ofertei
     */
    friend ostream& operator<<(ostream& stream, const Oferta& of);
};


