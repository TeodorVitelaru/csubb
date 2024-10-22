from domain.notare import Notare


class StudentValidator:
    def __init__(self):
        pass

    def validare_student(self, student):
        """
        valideaza un student dat
        :param student: studentul care se valideaza
        :return:
        """
        erori = []
        if student.get_studentID() > 1000:
            erori.append("ID-ul este mult prea mare")
        if len(student.get_nume()) < 3:
            erori.append("Numele este mult prea scurt")
        if student.get_grup() > 50 or student.get_grup == 0:
            erori.append("Grupa trebuie sa fie cuprinsa intre 1 si 50")
        if len(erori) > 0:
            erori_string = '\n'.join(erori)
            raise ValueError(erori_string)


class ProblemaValidator:
    def __init__(self):
        pass

    def validare_problema(self, problema):
        """
        valideaza o problema data
        :param problema:  problema care se valideaza
        :return:
        """
        erori = []
        if problema.get_numar_problema() > 200 or problema.get_numar_problema() < 1:
            erori.append("Numarul problemei trebuie sa fie intre 1 si 200")
        if len(problema.get_descriere()) < 3:
            erori.append("Descrierea este prea scurta")

        if len(erori) > 0:
            erori_string = '\n'.join(erori)
            raise ValueError(erori_string)

class NotaValidator:
    def __init__(self):
        pass

    def validare_nota(self, notare: Notare):
        erori = []
        if notare.get_nota()<1 and notare.get_nota() > 10:
            erori.append("Nota trebuie sa fie cuprinsa intre 1 si 10")
        if notare.get_problema().get_numar_problema() > 200 or notare.get_problema().get_numar_problema() < 1:
            erori.append("Numarul problemei trebuie sa fie intre 1 si 200")
        if notare.get_student().get_studentID() > 1000:
            erori.append("ID-ul este mult prea mare")
        if len(erori) > 0:
            erori_string = '\n'.join(erori)
            raise ValueError(erori_string)