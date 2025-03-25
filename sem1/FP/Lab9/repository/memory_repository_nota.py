from domain.notare import Notare
from domain.problema import Problema
from domain.student import Student
from datetime import datetime

from repository.memory_repository_problema import ProblemaFileRepository
from repository.memory_repository_student import StudentFileRepository


class NotaInMemoryRepository:
    def __init__(self):
        self.__lista_note = []

    def store(self, notare:Notare):
        """
        Adauga o noua nota
        :param nota:
        :return:
        """
        if self.find(notare):
            raise ValueError("Problema aceasta deja a fost notata la acest student")
        self.__lista_note.append(notare)
    def find(self, nota:Notare):
        for note_noi in self.__lista_note:
            if note_noi == nota:
                return note_noi
        return None

    def get_all(self):
        return self.__lista_note

    def get_student_nota_nr_prob(self, nr_prob):
        lista_noua = []
        for notare in self.__lista_note:
            stud_nota = []
            if notare.get_problema().get_numar_problema() == nr_prob:
                stud_nota.append(notare.get_student())
                stud_nota.append(notare.get_nota())
                lista_noua.append(stud_nota)
        return lista_noua

    def get_note_pentru_student(self, studentID):
        lista_note_stud = []
        for notare in self.__lista_note:
            if notare.get_student().get_studentID() == studentID:
                lista_note_stud.append(notare.get_nota())
        return lista_note_stud

    def get_studenti(self):
        lista_noua = []
        for notare in self.__lista_note:
            if notare.get_student() not in lista_noua:
                lista_noua.append(notare.get_student())
        return lista_noua

    def size(self):
        return len(self.__lista_note)



class NotaFileRepository:
    """
    Repo care gestioneaza fisiere
    """
    def __init__(self, filename, student_repo:StudentFileRepository, problema_repo:ProblemaFileRepository):
        self.__filename = filename
        self.__student_repo = student_repo
        self.__problema_repo = problema_repo

    def convert_to_date(self, deadline_str):
        return datetime.strptime(deadline_str, '%Y/%m/%d').date()

    def read_from_file(self):
        with open(self.__filename, mode="r") as f:
            notari = []
            lines = f.readlines()
            line = [line.strip() for line in lines if line.strip()!='']
            for line in lines:
                notare_elements = line.split(',')
                notare_elements =[element.strip() for element in notare_elements]
                studentID = int(notare_elements[0])
                nr_prob = int(notare_elements[1])
                nota = int(notare_elements[2])
                student = self.__student_repo.find(studentID)
                problema = self.__problema_repo.find(nr_prob)
                notare = Notare(student, problema, nota)
                notari.append(notare)
        return notari

    def write_to_file(self, lista_notari):
        with open(self.__filename, mode="w") as f:
            for notare in lista_notari:
                notare_elements = [notare.get_student().get_studentID(), notare.get_problema().get_numar_problema(), notare.get_nota()]
                notare_elements = [str(element) for element in notare_elements]
                line = ', '.join(notare_elements) + '\n'
                f.write(line)

    def store(self, notare):
        lista_notari = self.read_from_file()
        if self.find(notare) is not None:
            raise ValueError("Exista deja aceasta notare!")
        lista_notari.append(notare)
        self.write_to_file(lista_notari)


    def find(self, notare:Notare):
        for nota in self.read_from_file():
            if nota == notare:
                return nota
        return None

    def get_all(self):
        return self.read_from_file()

    def get_student_nota_nr_prob(self, nr_prob):
        lista_noua = []
        lista_notari = self.read_from_file()
        for notare in lista_notari:
            stud_nota = []
            if notare.get_problema().get_numar_problema() == nr_prob:
                stud_nota.append(notare.get_student())
                stud_nota.append(notare.get_nota())
                lista_noua.append(stud_nota)
        return lista_noua

    def get_students_grupa(self, grupa):
        lista_noua = []
        for student in self.__student_repo.get_all():
            if student.get_grup() == grupa:
                lista_noua.append(student)
        return lista_noua

    def get_note_pentru_student(self, studentID):
        lista_note_stud = []
        lista_notari = self.read_from_file()
        for notare in lista_notari:
            if notare.get_student().get_studentID() == studentID:
                lista_note_stud.append(notare.get_nota())
        return lista_note_stud

    def get_studenti(self):
        lista_noua = []
        lista_notari = self.read_from_file()
        for notare in lista_notari:
            if notare.get_student() not in lista_noua:
                lista_noua.append(notare.get_student())
        return lista_noua

    def size(self):
        return len(self.read_from_file())

