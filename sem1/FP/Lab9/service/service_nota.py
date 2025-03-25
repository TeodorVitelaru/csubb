from domain.notare import Notare
from domain.validare import NotaValidator
from repository.memory_repository_nota import NotaInMemoryRepository, NotaFileRepository
from repository.memory_repository_problema import ProblemaInMemoryRepository
from repository.memory_repository_student import StudentInMemoryRepository


class NotaController:
    def __init__(self, note_repo: NotaFileRepository, note_validator: NotaValidator, student_repo: StudentInMemoryRepository, problema_repo: ProblemaInMemoryRepository):
        self.__note_repo = note_repo
        self.__note_validator = note_validator
        self.__student_repo = student_repo
        self.__problema_repo = problema_repo

    def adaugare_nota(self, studentID, nr_prob, nota):
        """
        Adaugare de note pentru un student la o anumita problema
        :param studentID:
        :param nr_prob:
        :param nota:
        :return:
        """
        student = self.__student_repo.find(studentID)
        if student is None:
            raise ValueError("Nu s a gasit student cu acest id!")
        problema = self.__problema_repo.find(nr_prob)
        if problema is None:
            raise ValueError("Nu exista problema cu acest numar")
        notare = Notare(student, problema, nota)
        #self.__note_validator.validare_nota()
        self.__note_repo.store(notare)

    def sortare_dupa_prob_nume(self, nr_prob):
        """
        Sortarea studentilor alfabetic pentru o problema
        :param nr_prob:
        :return:
        """
        problema = self.__problema_repo.find(nr_prob)
        if problema is None:
            raise ValueError("Nu exista problema cu acest numar!")
        lista_notare_problema = self.__note_repo.get_student_nota_nr_prob(nr_prob)
        lista_notare_problema = sorted(lista_notare_problema, key = lambda x:x[0].get_nume())
        return  lista_notare_problema

    def sortare_dupa_prob_nota(self, nr_prob):
        """
        Sortarea studentilor dupa nota pentru o problema
        :param nr_prob:
        :return:
        """
        problema = self.__problema_repo.find(nr_prob)
        if problema is None:
            raise ValueError("Nu exista problema cu acest numar!")
        lista_notare_problema = self.__note_repo.get_student_nota_nr_prob(nr_prob)
        lista_notare_problema = sorted(lista_notare_problema, key=lambda x: x[1])
        return lista_notare_problema

    def medie_mai_mic_5(self):
        lista_notari = self.__note_repo.get_all()
        if lista_notari is []:
            raise ValueError("Nu exista nicio notare")
        lista_studenti = self.__note_repo.get_studenti()
        lista_stud_medie = []
        for student in lista_studenti:
            media = 0
            lista_note = self.__note_repo.get_note_pentru_student(student.get_studentID())
            numar_note = len(lista_note)
            for nota in lista_note:
                media += nota
            media = media/numar_note
            if media < 5:
                student_si_media = []
                student_si_media.append(student.get_nume())
                student_si_media.append(media)
                lista_stud_medie.append(student_si_media)
        return lista_stud_medie

    def studenti_fara_note(self):
        lista_noua = []
        lista_studenti_note = self.__note_repo.get_studenti()
        lista_studenti = self.__student_repo.get_all()
        for student in lista_studenti:
            if student not in lista_studenti_note:
                lista_noua.append(student)
        return lista_noua

    def media_din_grupa(self, grupa):
        lista_medii = []
        lista_studenti = self.__note_repo.get_students_grupa(grupa)
        for student in lista_studenti:
            media = 0
            lista_note = self.__note_repo.get_note_pentru_student(student.get_studentID())
            numar_note = len(lista_note)
            for nota in lista_note:
                media += nota
            media = media/numar_note
            lista_medii.append(media)
        valoare = 0
        for medie in lista_medii:
            valoare += medie


    def get_all_notes(self):
        return self.__note_repo.get_all()
