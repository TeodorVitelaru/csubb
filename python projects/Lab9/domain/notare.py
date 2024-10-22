
class Notare:
    def __init__(self, student, problema, nota):
        self.__student = student
        self.__problema = problema
        self.__nota = nota

    def get_student(self):
        return self.__student

    def get_problema(self):
        return self.__problema

    def get_nota(self):
        return self.__nota

    def set_student(self, student_nou):
        self.__student = student_nou

    def set_problema(self, problema_noua):
        self.__problema = problema_noua

    def set_nota(self, nota_noua):
        self.__nota = nota_noua

    def __str__(self):
        return ("Student: " + str(self.__student) + " || "
                " Problema: " + str(self.__problema) + " || " + " Nota:" + str(self.__nota))

    def __eq__(self, other):
        if self.__student == other.__student and self.__problema == other.__problema:
            return True
        return False