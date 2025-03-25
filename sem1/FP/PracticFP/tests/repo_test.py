from unittest import TestCase

from domain.melodie import Melodie
from repo.melodie_repo import MelodieFileRepository
from utils.file_utils import clear_file_content, copy_file_content


class TestRepo(TestCase):
    def setUp(self):
        clear_file_content("test_melodii.txt")
        copy_file_content("default_melodii.txt", "test_melodii.txt")
        self.test_repo = MelodieFileRepository("test_melodii.txt")

    def test_read_from_file(self):
        lista = self.test_repo.read_from_file()
        assert len(lista) == 5

    def test_write_to_file(self):
        lista = self.test_repo.read_from_file()
        self.test_repo.write_to_file(lista)
        assert len(self.test_repo.read_from_file()) == 5
        melodie = Melodie('asa', 'eu', 'Jazz', '01.01.2019')
        lista_melodie = self.test_repo.read_from_file()
        lista_melodie.append(melodie)
        assert self.test_repo.size() == 5
        self.test_repo.write_to_file(lista_melodie)
        assert self.test_repo.size() == 6

    def test_store(self):
        melodie = Melodie('asa', 'eu', 'Jazz', '01.01.2019')
        assert self.test_repo.size() == 5
        self.test_repo.store(melodie)
        assert  self.test_repo.size() == 6

    def test_modify(self):
        melodie = Melodie('Crying', 'teodor', 'Jazz', '01.01.2021')
        lista = self.test_repo.read_from_file()
        assert lista[0].get_gen() == 'Rock'
        assert lista[0].get_data() == '12.12.2024'
        self.test_repo.modify(melodie)
        lista_noua = self.test_repo.read_from_file()
        assert lista[0].get_gen() == 'Rock'
        assert lista[0].get_data() == '12.12.2024'

    def test_find(self):
        lista = self.test_repo.read_from_file()
        assert self.test_repo.find("Crying", 'teodor') is not None
        assert self.test_repo.find("bara", 'bara') is None
        assert self.test_repo.find("Ciudata", 'andrei') is not None
        melodie = self.test_repo.find("Ciudata", 'andrei')
        assert melodie.get_gen() == "Rock"
        assert melodie.get_titlu() == "Ciudata"

    def test_generate(self):
        melodie = self.test_repo.generate(['eu', 'tu', 'noi'],['eu', 'tu', 'noi'])
        assert (melodie.get_gen() in ["Rock", "Jazz", "Pop"]) == True
        assert (melodie.get_artist() in ['eu', 'tu', 'noi']) == True
        assert (melodie.get_titlu() in ['eu', 'tu', 'noi']) == True
        assert melodie.get_data() == "01.01.2020"

    def test_export(self):
        lista_melodii = self.test_repo.read_from_file()
        try:
            self.test_repo.export("test.txt", lista_melodii)
            assert True
        except ValueError:
            assert False