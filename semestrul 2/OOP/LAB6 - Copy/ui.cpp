#include <iostream>
#include <string>
#include "ui.h"

using namespace std;

void Consola::print_menu() {
    cout<<"MENIU\n";
    cout<<"1.Aduagare oferta\n";
    cout<<"2.Stergere oferta\n";
    cout<<"3.Modificare oferta\n";
    cout<<"4.Printare oferte\n";
    cout<<"5.Cautare oferta\n";
    cout<<"6.Filtrare oferte\n";
    cout<<"7.Sortare oferte\n";
    cout<<"8.Exit\n";
}

void Consola::adaugare_ui() {
    string denumire, destinatie, tip;
    char pr[100];
    int pret;
    cout<<"Denumirea: ";
    cin>>denumire;
    cout<<"Destinatia: ";
    cin>>destinatie;
    cout<<"Tipul: ";
    cin>>tip;
    cout<<"Pretul: ";
    cin>>pr;
    pret = atoi(pr);
    try{
        srv.adaugare_oferta(denumire, destinatie, tip, pret);
        cout<<"Oferta a fost adaugata cu succes!"<<endl;
    }
    catch (RepoException& re)
    {
        cout<< re.getErrorMessage();
    }
    catch (Exception exception)
    {
        cout<<exception.getMessage();
    }
}

void Consola::modificare_ui()
{
    string denumire, destinatie, tip_nou;
    char pr[100];
    int pret_nou;
    cout<<"Denumirea ofertei pe care vreti sa o schimbati: ";
    cin>>denumire;
    cout<<"Destinatia ofertei pe care vreti sa o schimbati: ";
    cin>>destinatie;
    cout<<"Tipul nou: ";
    cin>>tip_nou;
    cout<<"Pretul nou: ";
    cin>>pr;
    pret_nou = atoi(pr);
    try {
        srv.modificare_oferta(denumire, destinatie, tip_nou,pret_nou);
        cout<<"Modificare reusita!!\n";
    }
    catch (Exception exception)
    {
        cout<<exception.getMessage();
    }
    catch (RepoException& re)
    {
        cout<< re.getErrorMessage();
    }
}

void Consola::stergere_ui() {
    int poz;
    cout<<"Introduceti pozitia: ";
    cin>>poz;
    if(poz<0 || poz>=srv.get_all_oferte().size())
        cout<<"Introduceti o pozitie valida!"<<endl;
    try{
        srv.stergere_oferta(poz);
        cout<<"Stergere reusita!!\n";
    }
    catch (Exception exception)
    {
        cout<<exception.getMessage();
    }
    catch (RepoException& re)
    {
        cout<< re.getErrorMessage();
    }
}

void Consola::cautare_ui() {
    string denumire, destinatie;
    cout<<"Denumirea: ";
    cin>>denumire;
    cout<<"Destinatia: ";
    cin>>destinatie;
    try{
       cout<<srv.cautare_oferte(denumire,destinatie);
    }
    catch (Exception exception)
    {
        cout<<exception.getMessage();
    }
    catch (RepoException& re)
    {
        cout<< re.getErrorMessage();
    }
}

void Consola::filtrare_ui() {
    int nr;
    cout<<"1.destinatie   2.pret"<<endl;
    cout<<"alegeti o optiune: ";
    cin>>nr;
    if(nr == 1)
    {
        string destinatia;
        cout<<"Dati destinatia pentru care vreti sa vedeti ofertele: ";
        cin>>destinatia;
        print_all_oferte(srv.filtrare_destinatie(destinatia));
    }
    else if(nr == 2)
    {
        int pret;
        cout<<"Dati pretul pentru care vreti sa vedeti ofertele: ";
        cin>>pret;
        print_all_oferte(srv.filtrare_pret(pret));
    }
}

void Consola::sortare_ui() {
    if(!srv.get_all_oferte().empty())
    {
        string crit;
        cout << "Introduceti criteriul dupa care doriti sa faceti sortarea(1-denumire,2-destinatie,3-tip+pret): ";
        cin >> crit;
        if(crit == "1")
        {
            int ord;
            cout << "Introduceti ordinea de sortare(1-crescator,2-descrescator): ";
            cin >> ord;
            if(ord == 1 || ord==2)
            {
                srv.sortare_generica(cmp_denumire, ord);
                cout<<"Sortare reusita!"<<endl;
            }
            else{
                cout<<"Introduceti valori corecte!!"<<endl;
            }
        } else if(crit == "2")
        {
            int ord;
            cout << "Introduceti ordinea de sortare(1-crescator,2-descrescator): ";
            cin >> ord;
            if(ord == 1 || ord==2)
            {
                srv.sortare_generica(cmp_destinatie, ord);
                cout<<"Sortare reusita!"<<endl;
            }
            else{
                cout<<"Introduceti valori corecte!!"<<endl;
            }
        } else if(crit == "3")
        {
            int ord;
            cout << "Introduceti ordinea de sortare(1-crescator,2-descrescator): ";
            cin >> ord;
            if(ord == 1 || ord==2)
            {
                srv.sortare_generica(cmp_tip_pret, ord);
                cout<<"Sortare reusita!"<<endl;
            }
            else{
                cout<<"Introduceti valori corecte!!\n"<<endl;
            }
        }
    }
    else{cout<<"Lista este goala.NU se pot face sortari!!\n"<<endl;}
}

void Consola::print_all_oferte(VectorulMeu<Oferta> allOferte) {
    if(allOferte.size() == 0)
        cout<< "Nu exista oferte"<<endl;
    else{
        int cnt=0;
        for(int i=0; i<allOferte.size(); i++)
        {
            cout<<cnt<<"."<<allOferte[i];
            cnt++;
        }
    }
}

void Consola::run() {
    int running = 1;
    int cmd;
    //this->add_default_oferte();
    while (running)
    {
        print_menu();
        cout<<"Comanda este:";
        cin>>cmd;
        switch (cmd)
        {   case 1:
                adaugare_ui();
                break;
            case 8:
                running = 0;
                break;
            case 4:
                print_all_oferte(const_cast<VectorulMeu<Oferta> &>(srv.get_all_oferte()));
                break;
            case 3:
                modificare_ui();
                break;
            case 2:
                stergere_ui();
                break;
            case 5:
                cautare_ui();
                break;
            case 7:
                sortare_ui();
                break;
            default:
                break;

        }
    }
}