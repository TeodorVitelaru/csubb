#include <cassert>
#include "teste.h"
#include "Service.h"



void test_domain()
{
    Repo repo{"../test.txt"};
    Apartament ap{1, "ap1", 1,};
    assert(ap.get_suprafata() == 1);
    assert(ap.get_strada() == "ap1");
    assert(ap.get_pret() == 1);
    Apartament ap2{2, "ap2", 2};
    assert(ap2.get_suprafata() == 2);
    assert(ap2.get_strada() == "ap2");
    assert(ap2.get_pret() == 2);
    repo.del(ap);
    repo.del(ap2);

}

void test_store_repo()
{
    Repo repo{"../test.txt"};
    Apartament ap{1, "ap1", 1};
    repo.store(ap);
    assert(repo.get_all().size() == 1);
    assert(repo.get_all().at(0).get_suprafata() == 1);
    assert(repo.get_all().at(0).get_strada() == "ap1");
    assert(repo.get_all().at(0).get_pret() == 1);
    Apartament ap2{2, "ap2", 2};
    repo.store(ap2);
    assert(repo.get_all().size() == 2);
    assert(repo.get_all().at(1).get_suprafata() == 2);
    assert(repo.get_all().at(1).get_strada() == "ap2");
    assert(repo.get_all().at(1).get_pret() == 2);
    repo.del(ap);
    repo.del(ap2);
}

void test_delete_repo()
{
    Repo repo{"../test.txt"};
    Apartament ap{1, "ap1", 1};
    repo.store(ap);
    assert(repo.get_all().size() == 1);
    assert(repo.get_all().at(0).get_suprafata() == 1);
    assert(repo.get_all().at(0).get_strada() == "ap1");
    assert(repo.get_all().at(0).get_pret() == 1);
    Apartament ap2{2, "ap2", 2};
    repo.store(ap2);
    assert(repo.get_all().size() == 2);
    assert(repo.get_all().at(1).get_suprafata() == 2);
    assert(repo.get_all().at(1).get_strada() == "ap2");
    assert(repo.get_all().at(1).get_pret() == 2);
    repo.del(ap);
    assert(repo.get_all().size() == 1);
    assert(repo.get_all().at(0).get_suprafata() == 2);
    assert(repo.get_all().at(0).get_strada() == "ap2");
    assert(repo.get_all().at(0).get_pret() == 2);
    repo.del(ap2);
    assert(repo.get_all().size() == 0);
}

void test_stergere_service()
{
    Repo repo{"../test.txt"};
    Service serv{repo};
    Apartament ap{1, "ap1", 1};
    serv.stergere(ap);
    assert(serv.get_all().size() == 0);
    Apartament ap2{2, "ap2", 2};
    serv.stergere(ap2);
    assert(serv.get_all().size() == 0);
}

void test_filtrare_pret()
{
    Repo repo{"../test.txt"};
    Service serv{repo};
    Apartament ap{1, "ap1", 1};
    repo.store(ap);
    Apartament ap2{2, "ap2", 2};
    repo.store(ap2);
    vector<Apartament> v = serv.filtrare_pret(1, 2);
    assert(v.size() == 2);
    assert(v.at(0).get_pret() == 1);
    assert(v.at(1).get_pret() == 2);
    v = serv.filtrare_pret(2, 3);
    assert(v.size() == 1);
    assert(v.at(0).get_pret() == 2);
    v = serv.filtrare_pret(3, 4);
    assert(v.size() == 0);
    serv.stergere(ap);
    serv.stergere(ap2);
}

void test_filtrare_suprafata()
{
    Repo repo{"../test.txt"};
    Service serv{repo};
    Apartament ap{1, "ap1", 1};
    repo.store(ap);
    Apartament ap2{2, "ap2", 2};
    repo.store(ap2);
    vector<Apartament> v = serv.filtrare_suprafata(1, 2);
    assert(v.size() == 2);
    assert(v.at(0).get_suprafata() == 1);
    assert(v.at(1).get_suprafata() == 2);
    v = serv.filtrare_suprafata(2, 3);
    assert(v.size() == 1);
    assert(v.at(0).get_suprafata() == 2);
    v = serv.filtrare_suprafata(3, 4);
    assert(v.size() == 0);
    serv.stergere(ap);
    serv.stergere(ap2);
}


void test_all()
{
    test_domain();
    test_store_repo();
    test_delete_repo();
    test_stergere_service();
    test_filtrare_pret();
    test_filtrare_suprafata();
}