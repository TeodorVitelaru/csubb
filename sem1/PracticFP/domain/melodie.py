

class Melodie:
    """
    Clasa pentru melodie
    """
    def __init__(self, titlu, artist, gen, data):
        self.__titlu = titlu
        self.__artist = artist
        self.__gen = gen
        self.__data = data

    def get_titlu(self):
        return self.__titlu

    def get_artist(self):
        return self.__artist

    def get_gen(self):
        return self.__gen

    def get_data(self):
        return self.__data

    def __eq__(self, other):
        if self.__titlu==other.__titlu and self.__artist==other.__artist and self.__gen==other.__gen and self.__data==other.__data:
            return True
        return False

    def __str__(self):
        return "Titlu:" +str(self.__titlu)+" Artist: "+str(self.__artist) +" Gen:"+str(self.__gen)+" Data:"+str(self.__data)

    def __cmp__(self, other):
        if self.__data < other.__data:
            return True
        return False