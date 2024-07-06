#include <iostream>
#include <assert.h>
#include "teste.h"


void test_domain()
{
     Oferta o1{ "vacanta", "Suceava", "munte", 1400 };
     assert(o1.get_destinatie() == "Suceava");
     assert(o1.get_denumire() == "vacanta");
     assert(o1.get_tip() == "munte");
     assert(o1.get_pret() == 1400);
     o1.set_pret(100);
     o1.set_tip("mare");
     o1.set_denumire("aici");
     o1.set_destinatie("nuaici");
    assert(o1.get_destinatie() == "nuaici");
    assert(o1.get_denumire() == "aici");
    assert(o1.get_tip() == "mare");
    assert(o1.get_pret() == 100);
    cout<<o1;
}

void test_store()
{
    Repo repo;
    repo.store(Oferta{"La mare", "Mamaia", "all-inclusive", 2345});
    assert(repo.get_all_oferte().size()==1);
    repo.store(Oferta("Munte", "Sinaia", "all-inclusive", 1280));
    assert(repo.get_all_oferte().size()==2);
    try {
        repo.store(Oferta("La mare", "Mamaia", "all-inclusive", 2345));assert(false);
    }
    catch (RepoException& re)
    {
        assert(re.getErrorMessage() == "Oferta cu aceaste denumire si acest titlu exista deja!");
    }
}

void test_find()
{
    Oferta of1{"La mare", "Mamaia", "all-inclusive", 2345};
    Repo repo;
    try{
        repo.find("aici", "aici");
        //assert(false);
    } catch (RepoException& ex)
    {
        assert(true);
    }
    repo.store(of1);
    repo.find("La mare", "Mamaia");
}

void test_del()
{
    Repo repo;
    repo.store(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.get_all_oferte().size()==1);
    Oferta o1 = Oferta("La mare", "Mamaia", "all-inclusive", 2345);
    repo.del(0);
    assert(repo.get_all_oferte().size()==0);
}

void test_modify()
{
    Repo repo;
    repo.store(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.get_all_oferte()[0].get_pret() == 2345);
    Oferta of1{"La mare", "Mamaia", "munte", 1400};
    repo.modify(of1);
    assert(repo.get_all_oferte()[0].get_pret() == 1400);
}

void test_adaugare_service()
{
    Repo repo;
    Validator valid;
    Service service{repo, valid};
    assert(service.get_all_oferte().size()==0);
    service.adaugare_oferta("La Mare", "Mamaia", "allinclusive", 2345);
    assert(service.get_all_oferte().size()==1);
    service.adaugare_oferta("100", "nuj", "fgfg", 123);
    assert(true);
}

void test_stergere_service()
{
    Repo repo;
    Validator valid;
    Service service{repo, valid};
    repo.store(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.get_all_oferte().size()==1);
    //service.stergere_oferta(1);
    assert(repo.get_all_oferte().size()==1);
    service.stergere_oferta(0);
    assert(0 == service.get_all_oferte().size());
}

void test_modificare_service()
{
    Repo repo;
    Validator valid;
    Service service{repo, valid};
    service.adaugare_oferta("La mare", "Mamaia", "allinclusive", 2345);
    assert(repo.get_all_oferte().size()==1);
    service.modificare_oferta("La mare", "Mamaia", "trei zile", 1000);
    Oferta o = service.cautare_oferte("La mare", "Mamaia");
    assert(o.get_tip()=="trei zile");
    assert(o.get_pret()==1000);
}

void test_filtrare_dest()
{
    Repo repo;
    Validator valid;
    Service service{repo, valid};
    repo.store(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.get_all_oferte().size()==1);
    repo.store(Oferta("Plaja", "Mamaia", "-", 400));
    repo.store(Oferta("Munte", "Sinaia", "all-inclusive", 1234));
    vector<Oferta> listaFiltrata1 = service.filtrare_destinatie("Mamaia");
    assert(listaFiltrata1.size()==2);
    assert(listaFiltrata1[0].get_pret()==2345);
    assert(listaFiltrata1[1].get_pret()==400);
    vector<Oferta> listaFiltrata2 = service.filtrare_destinatie("Exemplu");
    assert(listaFiltrata2.empty());
}

void test_filtrare_pret()
{
    Repo repo;
    Validator valid;
    Service service{repo, valid};
    repo.store(Oferta("La mare", "Mamaia", "all-inclusive", 2345));
    assert(repo.get_all_oferte().size()==1);
    repo.store(Oferta("Plaja", "Mamaia", "-", 400));
    repo.store(Oferta("Munte", "Sinaia", "all-inclusive", 1234));
    vector<Oferta> listaFiltrata1 = service.filtrare_pret(2000);
    assert(listaFiltrata1.size()==2);
    assert(listaFiltrata1[0].get_pret()==400);
    assert(listaFiltrata1[1].get_pret()==1234);
    vector<Oferta> listaFiltrata2 = service.filtrare_pret(10);
    assert(typeid(service.filtrare_pret(100))== typeid(vector<Oferta>));
    assert(listaFiltrata2.size()==0);
}

void test_sortare_service()
{
    Repo repo;
    Validator valid;
    Service service{ repo, valid };
    service.adaugare_oferta("a", "b", "csc", 100);
    service.adaugare_oferta("sa", "a", "c", 50);
    service.adaugare_oferta("t", "y", "c", 63);
    service.adaugare_oferta("o", "xc", "m", 100);

    service.sortare_generica(cmp_denumire, 1);
    assert(service.get_all_oferte().size() == 4);
    assert(service.get_all_oferte()[0].get_denumire() == "a");
    assert(service.get_all_oferte()[1].get_denumire() == "o");

    service.sortare_generica(cmp_destinatie, 0);
    assert(service.get_all_oferte().size() == 4);
    assert(service.get_all_oferte()[0].get_destinatie() == "y");
    assert(service.get_all_oferte()[1].get_destinatie() == "xc");


    service.sortare_generica(cmp_tip_pret, 1);
    assert(service.get_all_oferte().size() == 4);
    assert(service.get_all_oferte()[0].get_tip() == "c");
    assert(service.get_all_oferte()[0].get_pret() == 50);
    assert(service.get_all_oferte()[1].get_tip() == "c");
    assert(service.get_all_oferte()[1].get_pret() == 63);


}

void test_all(){
    test_domain();
    test_store();
    test_find();
    test_del();
    test_modify();

    test_adaugare_service();
    test_stergere_service();
    test_modificare_service();
    test_filtrare_dest();
    test_filtrare_pret();
    test_sortare_service();
}