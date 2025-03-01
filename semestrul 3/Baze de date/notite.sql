

SELECT RAND(); -- Valoare între 0 și 1
SELECT FLOOR(RAND() * 10); -- Număr întreg între 0 și 9


--cheie primara
id_preparat int primary key identity(1,1),


--cheie straina
id_comanda int foreign key references Comenzi(id_comanda),


--declarare int
declare @nr_comenzi_sterse int
	set @nr_comenzi_sterse=0

--declarare tabel
declare @Comenzi_de_sters Table (id_comanda int)

--inner join
select distinct C.id_comanda from Comenzi as C
	inner join Comenzi_Preparate as CP on C.id_comanda=CP.id_comanda


--creare view
create or alter view ComandaBogdan
as

--cheie compusa
PRIMARY KEY (id_parinte1, id_parinte2)


--sterge din tabel
DELETE FROM NumeTabela WHERE coloana = valoare;

--actualizare tabel
UPDATE NumeTabela
SET coloana1 = valoare1, coloana2 = valoare2
WHERE conditie;

--ceva compus
CREATE PROCEDURE StergeComenzi(@ingredient VARCHAR(100))
AS
BEGIN
    DELETE FROM Comenzi
    WHERE id IN (
        SELECT comanda_id
        FROM Ingrediente
        WHERE denumire = @ingredient
    );
END;

--group by!!s
select C.id_comanda, sum(P.pret) as Suma from Comenzi as C
	inner join Comenzi_Preparate as CP on CP.id_comanda=C.id_comanda
	inner join Preparate as P on CP.id_preparat=P.id_preparat
	inner join Clienti as Cl on Cl.id_client=C.id_client
	where Cl.nume='Bogdan Ioan'
	group by (id_comanda)

--update la date din tabel
UPDATE Produs p
    INNER JOIN CategorieProdus cp ON p.categorie_nume = cp.nume
    INNER JOIN TarabaCategorie tc ON tc.categorie_nume = cp.nume
    INNER JOIN Taraba t ON t.numar = tc.taraba_nr AND t.hala_litera = tc.hala_litera
    SET p.pret = CASE
                    WHEN p.pret < 100 THEN p.pret + 10
                    WHEN p.pret > 200 THEN p.pret + 50
                    ELSE p.pret * 1.1
                 END
    WHERE t.numar = taraba_nr AND t.hala_litera = hala_litera;


--update la date din tabel
UPDATE Produs
    SET pret = pret + 50
    WHERE categorie_nume IN (
        SELECT categorie_nume
        FROM TarabaCategorie
        WHERE taraba_numar = numar_taraba AND hala_litera = hala_litera
    ) AND pret > 200;