from datetime import datetime

from domain.problema import Problema
from domain.validare import ProblemaValidator
from repository.memory_repository_problema import ProblemaInMemoryRepository
from service.service_problema import ProblemaController

def convert_to_date(deadline_str):
    return datetime.strptime(deadline_str, '%Y/%m/%d').date()

def test_adaugare_problema():
    repo = ProblemaInMemoryRepository()
    validator = ProblemaValidator()
    problema_service = ProblemaController(repo, validator)
    problema_service.adauga_problema(1,  "dada", convert_to_date("2021/01/01"))
    problema_service.adauga_problema(2,  "nunu", convert_to_date("2021/01/01"))
    test_lista_probleme = problema_service.get_all_problems()
    assert (len(test_lista_probleme) == 2)
test_adaugare_problema()

def test_stergere_problema():
    repo = ProblemaInMemoryRepository()
    validator = ProblemaValidator()
    problema_service = ProblemaController(repo, validator)
    problema_service.adauga_problema(1,  "dada", convert_to_date("2021/01/01"))
    problema_service.adauga_problema(2,  "nunu", convert_to_date("2021/01/01"))
    assert (len(problema_service.get_all_problems()) == 2)
    problema_service.sterge_problema(1)
    assert (len(problema_service.get_all_problems()) == 1)
    try:
        problema_service.sterge_problema(4)
        assert False
    except ValueError:
        assert True
    problema_service.sterge_problema( 2)
    assert (len(problema_service.get_all_problems()) == 0)

test_stergere_problema()

def test_modificare_problema():
    repo = ProblemaInMemoryRepository()
    validator = ProblemaValidator()
    problema_service = ProblemaController(repo, validator)
    problema_service.adauga_problema(1, "dada", convert_to_date("2021/01/01"))
    problema_service.adauga_problema(2,  "nunu", convert_to_date("2021/01/01"))
    problema = Problema(3,  'abc', convert_to_date("2022/01/01"))
    assert (len(problema_service.get_all_problems()) == 2)
    problema_modificata = problema_service.modificare_problema(1,  problema)
    assert (len(problema_service.get_all_problems()) == 2)
    assert problema_modificata.get_descriere() == "dada"
test_modificare_problema()

def test_filtrare_problema():
    repo = ProblemaInMemoryRepository()
    validator = ProblemaValidator()
    problema_service = ProblemaController(repo, validator)
    problema_service.adauga_problema(1,  "dada", convert_to_date("2021/02/01"))
    problema_service.adauga_problema(2, "nunu", convert_to_date("2021/02/06"))
    problema_service.adauga_problema(3,  "eueu", convert_to_date("2021/01/23"))
    problema_service.adauga_problema(4,  "tutu", convert_to_date("2021/04/01"))
    assert len(problema_service.get_all_problems()) == 4
    test_lista_filtrata = problema_service.filtrare_dupa_deadline(convert_to_date("2021/02/02"))
    assert len(test_lista_filtrata) == 2
    assert test_lista_filtrata[0].get_descriere() == "dada"
    assert test_lista_filtrata[1].get_descriere() != "nunu"
    assert test_lista_filtrata[1].get_descriere() == "eueu"
test_filtrare_problema()
