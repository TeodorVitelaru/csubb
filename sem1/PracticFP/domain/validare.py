from datetime import datetime

class MelodieValidator:
    def __init__(self):
        pass

    def validare_melodie(self, melodie):
        erori = []
        genuri = ["Rock", "Pop", "Jazz"]
        if melodie.get_gen() not in genuri:
            erori.append("Gen incorect!")
        if melodie.get_artist() == "":
            erori.append("Trebuie sepecificat artistul!")
        if melodie.get_titlu() == (""):
            erori.append("Trebuie sepecificat titlul!")
        data_str = melodie.get_data()
        data = data_str.split(".")
        data = [element.strip() for element in data]
        data = [int(element) for element in data]
        zi = data[0]
        luna= data[1]
        an = data[2]
        if zi<1 or zi>31 or luna<1 or luna>12 or an<0 or an>2024:
            erori.append("Introduceti o data valida!")
        if luna == 5 and zi > 2 and an == 2024:
            erori.append("Introduceti o data valida!")
        #erori.append("Introduceti o data valida!")

        if len(erori) > 0:
            erori_string = '\n'.join(erori)
            raise ValueError(erori_string)