class Student:
    def __init__(self, studentID, nume, grup):
        self.__studentID = studentID
        self.__nume = nume
        self.__grup = grup
    def get_studentID(self):
        return self.__studentID

    def get_nume(self):
        return str(self.__nume)

    def get_grup(self):
        return self.__grup

    def set_studentID(self, studentID_nou):
        self.__studentID = studentID_nou

    def set_nume(self, nume_nou):
        self.__nume = nume_nou

    def set_grupa(self, grupa_nou):
        self.__grup = grupa_nou

    def __str__(self):
        return "studentID: " + str(self.__studentID) + '//' + "Nume: " + self.__nume + '//' + "Grupa: " + str(self.__grup)

    def __eq__(self, other):
        if self.__studentID == other.__studentID and self.__nume == other.__nume and self.__grup == other.__grup:
            return True
        return False

