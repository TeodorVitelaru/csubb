import random

from domain.student import Student


class StudentInMemoryRepository:
    def __init__(self):
        self.__lista_studenti = []

    def store(self, student:Student):
        """
        adauga studentul in lista de studenti
        :param student: studentul adaugat
        :return: -; lista de studenti se modifica prin adaugarea la sfarsit a studentului dat
        """
        if self.find(student.get_studentID()):
            raise ValueError ("Exista deja student cu acest id")
        self.__lista_studenti.append(student)

    def find(self, id):
        for student in self.__lista_studenti:
            if student.get_studentID() == id:
                return student
        return None

    def delete(self, id):
        student_to_delete = self.find(id)
        if student_to_delete is None:
            raise ValueError("Nu exista student cu acest id!")
        self.__lista_studenti.remove(student_to_delete)
        return student_to_delete

    def modify(self, id, student_nou):
        student_to_modify = self.find(id)
        if student_to_modify is None:
            raise ValueError("Nu exista student cu acest id!")
        lista_noua = []
        for student in self.__lista_studenti:
            if student.get_studentID() == id:
                lista_noua.append(student_nou)
            else:
                lista_noua.append(student)
        self.set_lista_studenti(lista_noua)
        return student_to_modify

    def get_all(self) -> list:
        """
        Returneaza intreaga lista de studenti
        :return:
        """
        return self.__lista_studenti

    def set_lista_studenti(self, lista_noua):
        """
        Modifica lista curenta de studenti
        :param lista_noua: lista cu care trebuie inlocuita lista actuala
        :return:
        """
        self.__lista_studenti = lista_noua

    def size(self):
        return len(self.__lista_studenti)

    def random_students(self):
        """
        Generare random de studenti
        :return:
        """
        lista_nume = ["Teodor", "Andrei", "Mihaela", "Florin", "George", "Mihai"]

        lista_grupe = [1, 2, 3, 4, 5, 6, 7]
        studentID = random.randint(1, 10)
        nume = random.choice(lista_nume)
        grupa = random.choice(lista_grupe)
        student = Student(studentID, nume, grupa)
        return student




class StudentFileRepository:
    """
    Repository care gestioneaza date din fisier
    """

    def __init__(self, filename):
        self.__filename = filename

    def read_from_file(self):
        with open(self.__filename, mode="r") as f:
            students = []
            lines = f.readlines()
            for line in lines:
                elements = line.split(',')
                elements = [element.strip() for element in elements]
                studentID = int (elements[0])
                nume = elements[1]
                grupa = int (elements[2])
                student = Student(studentID, nume, grupa)
                students.append(student)
            return students

    def write_to_file(self, lista_studenti):
        with open(self.__filename, mode="w") as f:
            for student in lista_studenti:
                student_elements = [student.get_studentID(), student.get_nume(), student.get_grup()]
                student_elements = [str(element) for element in student_elements]
                line = ', '.join(student_elements) + '\n'
                f.write(line)

    def store(self, student):
        """
        Pune studentul in lista studenti si il scrie in fisier
        :param student:
        :return:
        """
        if self.find(student.get_studentID()) is not None:
            raise ValueError("Exista deja student cu acest id!")
        lista_studenti = self.read_from_file()
        lista_studenti.append(student)
        self.write_to_file(lista_studenti)

    def find(self, studentID):
        """
        Gaseste studentul cu ID dat
        :param studentID:
        :return:
        """
        lista_studenti = self.read_from_file()
        for student in lista_studenti:
            if student.get_studentID() == studentID:
                return student
        return None

    def delete(self, studentID):
        """
        Sterge student cu id dat
        :param studentID:
        :return:
        """
        lista_studenti = self.read_from_file()
        student_to_delete = self.find(studentID)
        lista_noua = []
        if student_to_delete is None:
            raise ValueError("Nu exista student cu acest id!")
        lista_studenti.remove(student_to_delete)
        self.write_to_file(lista_studenti)
        return student_to_delete

    def modify(self, id, student_nou):
        student_to_modify = self.find(id)
        if student_to_modify is None:
            raise ValueError("Nu exista student cu acest id!")
        lista_noua = []
        lista_studenti = self.read_from_file()
        for student in lista_studenti:
            if student.get_studentID() == id:
                lista_noua.append(student_nou)
            else:
                lista_noua.append(student)
        self.write_to_file(lista_noua)
        return student_to_modify

    def get_all(self):
        """
        Retunreaza lista de studenti
        :return:
        """
        return self.read_from_file()

    def size(self):
        return len(self.read_from_file())

    def random_students(self):
        """
                    Generare random de studenti
                    :return:
                    """
        lista_nume = ["Teodor", "Andrei", "Mihaela", "Florin", "George", "Mihai"]

        lista_grupe = [1, 2, 3, 4, 5, 6, 7]
        studentID = random.randint(1, 10)
        nume = random.choice(lista_nume)
        grupa = random.choice(lista_grupe)
        student = Student(studentID, nume, grupa)
        return student

    def size(self):
        return len(self.read_from_file())

