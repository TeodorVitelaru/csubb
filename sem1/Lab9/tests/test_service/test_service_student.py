from unittest import TestCase

from domain.student import Student
from domain.validare import StudentValidator
from repository.memory_repository_student import StudentInMemoryRepository
from service.serivice_student import StudentController

class TestInMemoryStudent(TestCase):

    def setUp(self):
        self.repo = StudentInMemoryRepository()
        self.validator = StudentValidator()
        self.student_service = StudentController(self.repo, self.validator)

    def test_adaugare(self):
        self.student_service.adauga_student(1, 'teodor', 2)
        test_student_list = self.student_service.get_all_students()
        assert (len(test_student_list) == 1)
        try:
            self.student_service.adauga_student(1, 'teo', 23)
            assert False
        except ValueError:
            assert True

    def test_stergere(self):
        self.student_service.adauga_student(1, 'teo', 2)
        self.student_service.adauga_student(2, 'andra', 2)
        assert (len(self.student_service.get_all_students()) == 2)
        self.student_service.stergere_student(1)
        assert (len(self.student_service.get_all_students()) == 1)
        try:
            self.student_service.stergere_student(34)
            assert False
        except ValueError:
            assert True


    def test_modificare(self):
        self.student_service.adauga_student(1, 'teodor', 2)
        self.student_service.adauga_student(2, 'andra', 2)
        student = Student(3, 'andrei', 3)
        assert (len(self.student_service.get_all_students()) == 2)
        student_modificat = self.student_service.modificare_student(1, student)
        assert (len(self.student_service.get_all_students()) == 2)
        assert student_modificat.get_nume() == 'teodor'


    def test_filtrare(self):
        self.student_service.adauga_student(1, 'teodor', 2)
        self.student_service.adauga_student(3, 'andrei', 3)
        self.student_service.adauga_student(4, 'andra', 2)
        self.student_service.adauga_student(5, 'stefan', 4)
        assert len(self.student_service.get_all_students()) == 4
        test_lista_filtrare = self.student_service.filtrare_dupa_grupa(2)
        assert len(test_lista_filtrare) == 2
        assert test_lista_filtrare[0].get_nume() == 'teodor'
        assert test_lista_filtrare[1].get_nume() != 'andrei'
        assert test_lista_filtrare[1].get_nume() == 'andra'


