from datetime import datetime

from domain.problema import Problema
from repository.memory_repository_problema import ProblemaInMemoryRepository

def convert_to_date(deadline_str):
    return datetime.strptime(deadline_str, '%Y/%m/%d').date()

def test_store():
    test_repo = ProblemaInMemoryRepository()
    assert (test_repo.size() == 0)

    problema1 = Problema(12,"abc", convert_to_date("2021/01/01"))
    test_repo.store(problema1)
    assert (test_repo.size() == 1)
    problema2 = Problema(12, "abc", convert_to_date("2021/01/01"))
    test_repo.store(problema2)
    assert (test_repo.size() == 2)
test_store()

def test_find():
    test_repo = ProblemaInMemoryRepository()
    assert (test_repo.size() == 0)
    problema1 =  Problema(12,"abc", convert_to_date("2021/01/01"))
    problema2 =  Problema(11, "abc", convert_to_date("2021/01/01"))
    test_repo.store(problema1)
    test_repo.store(problema2)
    assert (test_repo.find(1,) is None)
    prob_gasita = test_repo.find(12).get_descriere == 'abc'
    assert (test_repo.find(12) == problema1)
    assert (test_repo.find(11) == problema2)
test_find()

def test_delete():
    test_repo = ProblemaInMemoryRepository()
    assert (test_repo.size() == 0)
    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    problema2 = Problema(1, "andraeu", convert_to_date("2021/01/01"))
    test_repo.store(problema1)
    test_repo.store(problema2)
    assert (test_repo.size() == 2)
    prob_stearsa = test_repo.delete(12)
    assert prob_stearsa == problema1
    assert (test_repo.size() == 1)
test_delete()

def test_modify():
    test_repo = ProblemaInMemoryRepository()
    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    problema2 = Problema(1, "andraeu", convert_to_date("2021/01/01"))
    test_repo.store(problema1)
    test_repo.store(problema2)
    assert (test_repo.size() == 2)
    problema3 = Problema(23, "vvaaaaaai", convert_to_date("2021/01/01"))
    prob_modificata = test_repo.modify(12, problema3)
    assert prob_modificata == problema1
    assert prob_modificata.get_descriere == 'abc'
    assert (test_repo.size() == 2)
test_modify()

