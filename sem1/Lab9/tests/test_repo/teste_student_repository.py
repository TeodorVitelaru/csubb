from unittest import TestCase

from domain.student import Student
from repository.memory_repository_student import StudentInMemoryRepository, StudentFileRepository
from utils.file_utils import clear_file_content, copy_file_content


def test_add_repo():
    test_repo = StudentInMemoryRepository()
    assert (test_repo.size() == 0)

    student = Student(1, "Teoor", 2)
    test_repo.store(student)
    assert (test_repo.size() == 1)
    student2 = Student(2, "andra", 2)
    test_repo.store(student2)
    assert (test_repo.size() == 2)
test_add_repo()

def test_delete_repo():
    test_repo = StudentInMemoryRepository()
    assert (test_repo.size() == 0)
    student1 = Student (1, "teodor", 2)
    student2 = Student(2, "andra", 2)
    test_repo.store(student1)
    test_repo.store(student2)
    assert (test_repo.size() == 2)
    deleted_student = test_repo.delete(1)
    assert (test_repo.size() == 1)
    assert (deleted_student.get_nume() == "teodor")
test_delete_repo()

def test_find():
    test_repo = StudentInMemoryRepository()
    student1 = Student(1, 'teodor', 2)
    student2 = Student(2, 'andra', 2)
    test_repo.store(student1)
    test_repo.store(student2)
    assert (test_repo.find(3) is None)
    assert (test_repo.find(1) == student1)
test_find()

def test_modify():
    test_repo = StudentInMemoryRepository
    student1 = Student(1, 'teodor', 2)
    student2 = Student(2, 'andra', 2)
    alt_student = Student(4, 'mama', 4)
    student_modificat = test_repo.modify(1, alt_student)
    assert (student_modificat.get_nume() == 'teodor')
    assert (student_modificat.get_studentID() == 1)
    assert (test_repo.size() == 2)
test_modify()


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
        assert self.test_repo.delete(9) is None


    def test_modify(self):
        student_nou = Student(5, "Rufus", 10)
        lista_studenti = self.test_repo.read_from_file()
        assert lista_studenti[0].get_nume() == "Teodor"
        assert lista_studenti[0].get_grup() == 2
        student_to_modify = self.test_repo.modify(1, student_nou)
        lista_studenti_noua = self.test_repo.read_from_file()
        assert lista_studenti_noua[0].get_nume() == "Rufus"
        assert lista_studenti_noua[0].get_grup() == 10
