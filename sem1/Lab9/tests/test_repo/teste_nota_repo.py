from domain.notare import Notare
from domain.problema import Problema
from domain.student import Student
from repository.memory_repository_nota import NotaInMemoryRepository
from datetime import datetime

def convert_to_date(deadline_str):
    return datetime.strptime(deadline_str, '%Y/%m/%d').date()

def test_store():
    test_repo = NotaInMemoryRepository()
    assert test_repo.size() == 0
    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    student = Student(1, "Teodor", 2)
    notare = Notare(student, problema1, 10)
    assert notare.get_student().get_nume() == "Teodor"
    assert notare.get_nota() == 10
    test_repo.store(notare)
    assert test_repo.size() == 1
    problema2 = Problema(1, "abc", convert_to_date("2021/01/01"))
    student1 = Student(3, "Teor", 2)
    notare1 = Notare(student1, problema2, 9)
    test_repo.store(notare1)
    assert test_repo.size() == 2
test_store()

def test_find():
    test_repo = NotaInMemoryRepository()
    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    student = Student(1, "Teodor", 2)
    student1 = Student(2, "boss", 4)
    notare = Notare(student, problema1, 10)
    assert test_repo.size() == 0
    test_repo.store(notare)
    assert test_repo.size() == 1
    notare2 = Notare(student, problema1, 10)
    gasit = test_repo.find(notare2)
    assert gasit == notare
    notare3 = Notare(student1 ,problema1, 10)
    gasit2 = test_repo.find(notare3)
    assert gasit2 == None
test_find()



