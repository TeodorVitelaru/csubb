from domain.problema import Problema
from domain.student import Student
from domain.validare import NotaValidator
from repository.memory_repository_nota import NotaInMemoryRepository
from repository.memory_repository_problema import ProblemaInMemoryRepository
from repository.memory_repository_student import StudentInMemoryRepository
from service.service_nota import NotaController
from datetime import datetime

def convert_to_date(deadline_str):
    return datetime.strptime(deadline_str, '%Y/%m/%d').date()



def test_adaugare_nota():
    note_repo = NotaInMemoryRepository()
    nota_validator = NotaValidator()
    student_repo = StudentInMemoryRepository()
    problema_repo = ProblemaInMemoryRepository()
    nota_service = NotaController(note_repo, nota_validator, student_repo, problema_repo)

    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema1)
    student = Student(1, "Teoor", 2)
    student_repo.store(student)
    assert len(nota_service.get_all_notes()) == 0
    nota_service.adaugare_nota(1, 12, 10)
    assert len(nota_service.get_all_notes()) == 1
test_adaugare_nota()

def test_sortare_dupa_prob_nume():
    note_repo = NotaInMemoryRepository()
    nota_validator = NotaValidator()
    student_repo = StudentInMemoryRepository()
    problema_repo = ProblemaInMemoryRepository()
    nota_service = NotaController(note_repo, nota_validator, student_repo, problema_repo)

    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema1)
    problema2 = Problema(11, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema2)
    student = Student(1, "Teoor", 2)
    student_repo.store(student)
    assert len(nota_service.get_all_notes()) == 0
    nota_service.adaugare_nota(1, 12, 10)
    assert len(nota_service.get_all_notes()) == 1
    student1 = Student(3, "Andrei", 2)
    student_repo.store(student1)
    nota_service.adaugare_nota(3, 12, 10)
    student2 = Student(2, "Andrei", 2)
    student_repo.store(student2)
    nota_service.adaugare_nota(2, 11, 10)
    lista_sortare = nota_service.sortare_dupa_prob_nume(12)
    assert len(lista_sortare) == 2
    elements = lista_sortare[0]
    assert elements[0].get_nume() == "Andrei"
    new_elements = lista_sortare[1]
    assert new_elements[0].get_nume() == "Teoor"

    lista_noua = nota_service.sortare_dupa_prob_nume(11)
    assert len(lista_noua) == 1
test_sortare_dupa_prob_nume()

def test_sortare_dupa_prob_nota():
    note_repo = NotaInMemoryRepository()
    nota_validator = NotaValidator()
    student_repo = StudentInMemoryRepository()
    problema_repo = ProblemaInMemoryRepository()
    nota_service = NotaController(note_repo, nota_validator, student_repo, problema_repo)

    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema1)
    problema2 = Problema(11, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema2)
    student = Student(1, "Teodor", 2)
    student_repo.store(student)
    assert len(nota_service.get_all_notes()) == 0
    nota_service.adaugare_nota(1, 12, 8)
    assert len(nota_service.get_all_notes()) == 1
    student1 = Student(3, "Andrei", 2)
    student_repo.store(student1)
    nota_service.adaugare_nota(3, 12, 9)
    student2 = Student(2, "Mihai", 2)
    student_repo.store(student2)
    nota_service.adaugare_nota(2, 11, 10)
    lista_sortare = nota_service.sortare_dupa_prob_nota(12)
    assert len(lista_sortare) == 2
    elements = lista_sortare[0]
    assert elements[0].get_nume() == "Teodor"
    new_elements = lista_sortare[1]
    assert new_elements[0].get_nume() == "Andrei"

    lista_noua = nota_service.sortare_dupa_prob_nume(11)
    assert len(lista_noua) == 1
test_sortare_dupa_prob_nota()

def test_medie_mai_mic_5():
    note_repo = NotaInMemoryRepository()
    nota_validator = NotaValidator()
    student_repo = StudentInMemoryRepository()
    problema_repo = ProblemaInMemoryRepository()
    nota_service = NotaController(note_repo, nota_validator, student_repo, problema_repo)

    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema1)
    problema2 = Problema(11, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema2)
    student = Student(1, "Teodor", 2)
    student_repo.store(student)
    assert len(nota_service.get_all_notes()) == 0
    nota_service.adaugare_nota(1, 12, 5)
    assert len(nota_service.get_all_notes()) == 1
    nota_service.adaugare_nota(1, 11, 4)
    student1 = Student(3, "Andrei", 2)
    student_repo.store(student1)
    nota_service.adaugare_nota(3, 12, 9)
    student2 = Student(2, "Mihai", 2)
    student_repo.store(student2)
    nota_service.adaugare_nota(2, 11, 2)
    lista_mai_mic_5 = nota_service.medie_mai_mic_5()
    elements = lista_mai_mic_5[0]
    assert elements[0] == 'Teodor'
    assert elements[1] == 4.5
    assert len(lista_mai_mic_5) == 2

    nota_service.adaugare_nota(2, 12, 4)
    lista_mai_mic_5 = nota_service.medie_mai_mic_5()
    elements = lista_mai_mic_5[1]
    assert elements[0] == 'Mihai'
    assert elements[1] == 3
test_medie_mai_mic_5()

def test_studenti_fara_note():
    note_repo = NotaInMemoryRepository()
    nota_validator = NotaValidator()
    student_repo = StudentInMemoryRepository()
    problema_repo = ProblemaInMemoryRepository()
    nota_service = NotaController(note_repo, nota_validator, student_repo, problema_repo)

    problema1 = Problema(12, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema1)
    problema2 = Problema(11, "abc", convert_to_date("2021/01/01"))
    problema_repo.store(problema2)
    student1 = Student(1, "Teodor", 2)
    student_repo.store(student1)
    student2 = Student(2, "Marius", 3)
    student_repo.store(student2)
    student3 = Student(3, "Stefan", 2)
    student_repo.store(student3)

    nota_service.adaugare_nota(1, 12, 10)
    nota_service.adaugare_nota(1,11, 9)
    lista_fara_note = nota_service.studenti_fara_note()
    assert lista_fara_note[0].get_nume() == "Marius"
    assert lista_fara_note[0].get_grup() == 3
    assert lista_fara_note[1].get_nume() == "Stefan"
    assert lista_fara_note[1].get_grup() == 2
    assert len(lista_fara_note) == 2

    nota_service.adaugare_nota(2, 12, 6)
    lista_noua_fara_note = nota_service.studenti_fara_note()
    assert lista_noua_fara_note[0].get_nume() =="Stefan"
    assert len(lista_noua_fara_note) == 1
test_studenti_fara_note()
