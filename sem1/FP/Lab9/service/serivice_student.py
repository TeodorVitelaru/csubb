from domain.student import Student
from domain.validare import StudentValidator
from repository.memory_repository_student import StudentInMemoryRepository, StudentFileRepository


class StudentController:
    def __init__(self, repository: StudentFileRepository, student_validator: StudentValidator):
        self.__student_validator = student_validator
        self.__student_repo = repository

    def adauga_student(self, studentID, nume, grup):
        """
        adauga studentul in lista de studenti
        :param studentID:
        :param nume:
        :param grup:
        :return:
        :raises: ValueError daca id ul este deja folosit
        """

        student = Student(studentID, nume, grup)
        self.__student_validator.validare_student(student)
        self.__student_repo.store(student)

    def stergere_student(self, id:int):
        """
        Sterge student dupa id
        :param id:
        :return:
        :raises: ValueErorr daca nu exista student cu id dat
        """
        return self.__student_repo.delete(id)

    def modificare_student(self, id:int, student_nou:Student):
        """
        Modifica studentul cu id ul dat
        :param id:
        :param student_nou:
        :return:
        :raises: ValueErro daca nu exista student cu id dat
        """
        return self.__student_repo.modify(id, student_nou)

    def filtrare_dupa_grupa(self, grupa):
        lista_filtrata= []
        for student in self.__student_repo.get_all():
            if student.get_grup() == grupa:
                lista_filtrata.append(student)
        return lista_filtrata

    def generare_random(self):
        student = self.__student_repo.random_students()
        self.__student_repo.store(student)


    def get_all_students(self) -> list:
        """
        Returneaza lista cu toti studentii
        :return:
        """
        return self.__student_repo.get_all()