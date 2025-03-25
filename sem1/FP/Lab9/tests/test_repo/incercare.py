from unittest import TestCase

from domain.notare import Notare
from domain.problema import Problema
from domain.student import Student
from repository.memory_repository_nota import NotaFileRepository
from repository.memory_repository_problema import ProblemaFileRepository
from repository.memory_repository_student import StudentInMemoryRepository, StudentFileRepository
from utils.file_utils import clear_file_content, copy_file_content
from datetime import datetime


class TestStudentFile(TestCase):
    def setUp(self):
        clear_file_content('test_students.txt')
        copy_file_content('default_students.txt', 'test_students.txt')
        self.test_repo = StudentFileRepository('test_students.txt')


    def test_read_from_file(self):
        assert self.test_repo.size() == 4

    def test_write_from_file(self):
        pass

    def test_store(self):
        student = Student(5, "Andreea", 2)
        self.test_repo.store(student)
        assert self.test_repo.size() == 5

    def test_find(self):
        assert self.test_repo.size() == 4
        student1 = Student(5, 'Ionut', 2)
        student2 = Student(6, 'Adreea', 4)
        self.test_repo.store(student1)
        self.test_repo.store(student2)
        assert self.test_repo.size() == 6
        assert self.test_repo.find(7) is None
        assert self.test_repo.find(6) is  not None
        assert self.test_repo.find(8) is None
        assert self.test_repo.find(1) is not None

    def test_delete(self):
        student1 = Student(5, 'Ionut', 2)
        student2 = Student(6, 'Adreea', 4)
        student3 = Student(7, 'Ionut', 2)
        student4 = Student(8, 'Adreea', 4)
        self.test_repo.store(student1)
        self.test_repo.store(student2)
        self.test_repo.store(student3)
        self.test_repo.store(student4)
        assert self.test_repo.size() == 8

        deleted_student = self.test_repo.delete(5)
        assert self.test_repo.size() == 7
        assert deleted_student.get_nume() == "Ionut"
        try:
            self.test_repo.delete(9)
            assert False
        except ValueError:
            assert True


    def test_modify(self):
        student_nou = Student(5, "Rufus", 10)
        lista_studenti = self.test_repo.read_from_file()
        assert lista_studenti[0].get_nume() == "Teodor"
        assert lista_studenti[0].get_grup() == 2
        student_to_modify = self.test_repo.modify(1, student_nou)
        lista_studenti_noua = self.test_repo.read_from_file()
        assert lista_studenti_noua[0].get_nume() == "Rufus"
        assert lista_studenti_noua[0].get_grup() == 10






class TestProblemaFile(TestCase):
    """
    Teste pentru repositroy file
    """
    def setUp(self):
        clear_file_content('test_problems.txt')
        copy_file_content('default_problems.txt', 'test_problems.txt')
        self.test_repo = ProblemaFileRepository('test_problems.txt')

    def convert_to_date(self, deadline_str):
        return datetime.strptime(deadline_str, '%Y/%m/%d').date()


    def test_read_from_file(self):
        assert self.test_repo.size() == 3

    def test_write_to_file(self):
        pass

    def test_store(self):
        assert self.test_repo.size() == 3
        problema = Problema(4, "asaa", self.convert_to_date("2021/04/04"))
        self.test_repo.store(problema)
        assert self.test_repo.size() == 4
        lista_probleme = self.test_repo.get_all()
        assert lista_probleme[3].get_numar_problema() == 4
        assert lista_probleme[3].get_descriere() == "asaa"

    def test_find(self):
        assert self.test_repo.size() == 3
        assert self.test_repo.find(1) is not None
        assert self.test_repo.find(5) is None
        problema = Problema(12, "haaai", self.convert_to_date("2022/02/02"))
        self.test_repo.store(problema)
        assert self.test_repo.size() == 4
        assert self.test_repo.find(12) is not None

    def test_delete(self):
        assert self.test_repo.size() == 3
        problem_to_delete = self.test_repo.delete(1)
        assert self.test_repo.size() == 2
        assert problem_to_delete.get_numar_problema() == 1
        assert problem_to_delete.get_deadline() == self.convert_to_date("2021/01/01")
        try:
            self.test_repo.delete(5)
            assert False
        except ValueError:
            assert True

    def test_modify(self):
        problema_noua = Problema(12, "descriere", self.convert_to_date("2023/01/01"))
        assert self.test_repo.size() == 3
        lista_probleme = self.test_repo.get_all()
        assert lista_probleme[0].get_numar_problema() == 1
        assert lista_probleme[0].get_descriere() == "eueu"

        problem_to_modify = self.test_repo.modify(1, problema_noua)
        assert problem_to_modify.get_numar_problema() == 1
        assert problem_to_modify.get_deadline() == self.convert_to_date("2021/01/01")
        assert self.test_repo.size() == 3

        lista_probleme_noua = self.test_repo.get_all()
        assert lista_probleme_noua[0].get_numar_problema() == 12
        assert lista_probleme_noua[0].get_descriere() == "descriere"





class TestNotareFile(TestCase):
    def setUp(self):
        clear_file_content('test_notari.txt')
        copy_file_content('default_notare.txt', 'test_notari.txt')
        self.student_repo = StudentFileRepository("default_students.txt")
        self.problem_repo = ProblemaFileRepository("default_problems.txt")
        self.test_repo = NotaFileRepository('test_notari.txt', self.student_repo, self.problem_repo)

    def convert_to_date(self, deadline_str):
        return datetime.strptime(deadline_str, '%Y/%m/%d').date()

    def test_read_from_file(self):
        assert self.test_repo.size() == 3

    def write_to_file(self):
        pass

    def test_store(self):
        assert self.test_repo.size() == 3
        student = Student(5, "Andreea", 2)
        problema = Problema(4, "asaa", self.convert_to_date("2021/04/04"))
        notare = Notare(student, problema, 10)
        self.test_repo.store(notare)
        assert self.test_repo.size() == 4
        try:
            self.test_repo.store(notare)
            assert False
        except ValueError:
            assert True

    def test_find(self):
        student = Student(5, "Andreea", 2)
        problema = Problema(4, "asaa", self.convert_to_date("2021/04/04"))
        notare = Notare(student, problema, 6)
        problema1 = Problema(10, "asdasd", self.convert_to_date("2023/02/02"))
        notare1 = Notare(student, problema1, 5)
        self.test_repo.store(notare)
        lista_notari = self.test_repo.get_all()
        for notare in lista_notari:
            print(notare)
        assert self.test_repo.find(notare) is not None
        assert self.test_repo.find(notare1) is None




