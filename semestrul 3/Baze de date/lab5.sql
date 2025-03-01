use Lab1
GO;
------validari ----------
--validare sa nu fiel null sau ''
create or alter function Validate_Not_Empty(@value VARCHAR(100))
returns int
as
begin
	if @value is not null and @value != ''
		return 1;
	return 0;
end;
GO;

--existenta unei ligi
create or alter function Validate_Liga_Exists(@id INT)
returns int
begin
	if exists(SELECT 1 from Ligi where id_liga = @id)
		return 1;
	return 0;
end
GO;

--existenta unui stadion
create or alter function Validate_Stadion_Exists(@id INT)
returns int
begin
	if exists(select 1 from Stadioane where id_stadion=@id)
		return 1;
	return 0;
end
GO;

--existenta unui antrenor
create or alter function Validate_Antrenor_Exists(@id INT)
returns int
begin
	if exists(select 1 from Antrenori where id_antrenor=@id)
		return 1;
	return 0;
end
GO;

create or alter function Validate_Oras_Exists(@id int)
returns int
begin
	if exists(select 1 from Oras where id_oras=@id)
		return 1;
	return 0;
end
GO;

CREATE OR ALTER FUNCTION ValidateNumber (@value NVARCHAR(100))
RETURNS BIT
AS
BEGIN
    -- Returnează 1 dacă este un număr valid, altfel 0
    RETURN CASE 
        WHEN ISNUMERIC(@value) = 1 THEN 1
        ELSE 0
    END
END;
GO;




----operatii crud pentru----
---LIGI---
create or alter procedure crud_Ligi
@op varchar(40),
@id_liga varchar(40),
@id_oras varchar(40),
@nume_liga varchar(100),
@numar_echipe varchar(40)
as
begin
	declare @valid bit
	set @valid = 1

	if dbo.ValidateNumber(@id_liga) = 0 AND @op IN ('update', 'delete', 'select')
	begin
		print 'invalid id liga'
		set @valid=0;
	end

	if dbo.Validate_Oras_Exists(@id_oras)=0 and @op IN ('update', 'delete', 'select')
	begin
		print 'invalid oras'
		set @valid=0
	end

	if dbo.Validate_Not_Empty(@nume_liga) = 0 AND @op IN ('update', 'delete', 'insert')
	begin
		print 'invalid name'
		set @valid=0;
	end

	if dbo.ValidateNumber(@numar_echipe)=0 and @op IN ('update', 'delete', 'insert')
	begin
		print 'invalid numar echipe'
		set @valid = 0;
	end

	if @valid = 0
	begin
		print 'informatii invalide'
		return
	end

	if @op = 'select'
	begin
		select * from Ligi where id_liga=cast(@id_liga as int)
		print 'select done'
	end
	else if @op='update'
	begin
		UPDATE Ligi
        SET nume_liga = @nume_liga, numar_echipe = cast(@numar_echipe as int), id_oras = cast(@id_oras as int)
        WHERE id_liga = @id_liga 
		print 'update done'
	end
	else if @op='delete'
	begin
		delete Ligi
		where id_liga=@id_liga and id_oras=@id_oras
		print 'delete done'
	end
	else if @op='insert'
	begin
		INSERT INTO Ligi (id_liga, id_oras, nume_liga, numar_echipe)
        VALUES (@id_liga, @id_oras, @nume_liga, @numar_echipe)
        print 'Insert done'
	end
	else
		print 'Invalid command'
end
GO;

create or alter procedure crud_Ligi_Castigate
@op varchar(100),
@id_antrenor varchar(40),
@id_liga varchar(40),
@an_castigat varchar(40)
as
begin
	declare @valid bit
	set @valid = 1

	if dbo.Validate_Antrenor_Exists(@id_antrenor)=0 and @op IN ('update', 'delete', 'select')
	begin
		set @valid=0;
		print 'antrenor inexistent'
	end

	if dbo.Validate_Liga_Exists(@id_liga)=0 and @op IN ('update', 'delete', 'select')
	begin
		set @valid=0;
		print 'liga inexistenta'
	end

	if dbo.ValidateNumber(@an_castigat)=0 and @op IN ('update', 'delete', 'insert')
	begin
		set @valid=0;
		print 'invalid an'
	end

	if @op = 'select'
    begin
        SELECT LC.an_castigat, A.nume_antrenor, L.nume_liga
        FROM LigiCastigate LC
        INNER JOIN Antrenori A ON A.id_antrenor = LC.id_antrenor
        INNER JOIN Ligi L ON L.id_liga = LC.id_liga
        WHERE LC.id_liga = @id_liga and LC.id_antrenor=@id_antrenor
        print 'Select done'
    end
    else if @op = 'update'
    begin
        UPDATE LigiCastigate
        SET an_castigat = cast(@an_castigat as int), id_antrenor = cast(@id_antrenor as int), id_liga = cast(@id_liga as int)
        WHERE id_liga=@id_liga and id_antrenor=@id_antrenor
        print 'Update done'
    end
    else if @op = 'delete'
    begin
        DELETE FROM LigiCastigate
        WHERE id_liga=@id_liga and id_antrenor=@id_antrenor
        print 'Delete done'
    end
    else if @op = 'insert'
    begin
        INSERT INTO LigiCastigate (id_antrenor, id_liga, an_castigat)
        VALUES (cast(@id_antrenor as int), cast(@id_liga as int), cast(@an_castigat as int))
        print 'Insert done'
    end
    else
        print 'Invalid command'
end
GO;

CREATE OR ALTER PROCEDURE crudOras
(
    @op varchar(40),
    @id varchar(40),
    @nume_oras varchar(100)
)
AS
BEGIN
    DECLARE @valid BIT
    SET @valid = 1

    -- Validare date de intrare
    if dbo.validateNumber(@id) = 0
    begin
        SET @valid = 0
        print 'The city id is not a number'
    end
    if dbo.Validate_Not_Empty(@nume_oras) = 0 and @op IN ('update', 'delete', 'insert')
    begin
        SET @valid = 0
        print 'City name is not valid'
    end

    -- Dacă sunt erori, returnează
    if @valid = 0
    BEGIN
        print 'Invalid data'
        return
    END


    -- Operații CRUD
    if @op = 'select'
    begin
        SELECT nume_oras
        FROM Oras
        WHERE id_oras = @id
        print 'Select done'
    end
    else if @op = 'update'
    begin
        UPDATE Oras
        SET nume_oras = @nume_oras
        WHERE id_oras = @id
        print 'Update done'
    end
    else if @op = 'delete'
    begin
        DELETE FROM Oras
        WHERE id_oras = @id
        print 'Delete done'
    end
    else if @op = 'insert'
    begin
        INSERT INTO Oras (nume_oras)
        VALUES (@nume_oras)
        print 'Insert done'
    end
    else
        print 'Invalid command'
END
GO;

CREATE OR ALTER PROCEDURE crudStadioane
(
    @op varchar(40),
    @id varchar(40),
    @nume_stadion varchar(100),
    @capacitate varchar(40),
    @id_oras varchar(40)
)
AS
BEGIN
    DECLARE @valid BIT
    SET @valid = 1

    -- Validare date de intrare
    if dbo.validateNumber(@id) = 0
    begin
        SET @valid = 0
        print 'The stadium id is not a number'
    end
    if dbo.validateNumber(@id_oras) = 0
    begin
        SET @valid = 0
        print 'The city id is not a number'
    end
    if dbo.validateNumber(@capacitate) = 0 and @op IN ('update', 'insert')
    begin
        SET @valid = 0
        print 'Capacity is not a number'
    end
    if dbo.Validate_Not_Empty(@nume_stadion) = 0 and @op IN ('update', 'insert')
    begin
        SET @valid = 0
        print 'Stadium name is not valid'
    end

    -- Verifică existența orașului
    if not exists(SELECT * FROM Oras WHERE id_oras = @id_oras)
    begin
        SET @valid = 0
        print 'The city id does not exist'
    end

    -- Dacă sunt erori, returnează
    if @valid = 0
    BEGIN
        print 'Invalid data'
        return
    END


    -- Operații CRUD
    if @op = 'select'
    begin
        SELECT nume_stadion, capacitate_stadion, O.nume_oras
        FROM Stadioane S
        INNER JOIN Oras O ON O.id_oras = S.id_oras
        WHERE S.id_stadion = @id
        print 'Select done'
    end
    else if @op = 'update'
    begin
        UPDATE Stadioane
        SET nume_stadion = @nume_stadion, capacitate_stadion = cast(@capacitate as int), id_oras = cast(@id_oras as int)
        WHERE id_stadion = @id
        print 'Update done'
    end
    else if @op = 'delete'
    begin
        DELETE FROM Stadioane
        WHERE id_stadion = @id
        print 'Delete done'
    end
    else if @op = 'insert'
    begin
        INSERT INTO Stadioane (nume_stadion, capacitate_stadion, id_oras)
        VALUES (@nume_stadion, cast(@capacitate as int), cast(@id_oras as int))
        print 'Insert done'
    end
    else
        print 'Invalid command'
END
GO;


CREATE OR ALTER PROCEDURE crudAntrenori
(
    @op varchar(40),
    @id varchar(40),
    @nume_antrenor varchar(100),
    @data_nasterii varchar(100)
)
AS
BEGIN
    DECLARE @valid BIT
    SET @valid = 1

    -- Validare date de intrare
    if dbo.validateNumber(@id) = 0
    begin
        SET @valid = 0
        print 'The coach id is not a number'
    end
    if dbo.Validate_Not_Empty(@nume_antrenor) = 0 and @op IN ('update', 'insert')
    begin
        SET @valid = 0
        print 'The coach name is not valid'
    end

    -- Dacă sunt erori, returnează
    if @valid = 0
    BEGIN
        print 'Invalid data'
        return
    END

    -- Verifică existența antrenorului
    if dbo.Validate_Antrenor_Exists(cast(@id as int)) = 0 and @op IN ('update', 'select', 'delete')
    begin
        print 'The coach id is not in the table'
        return
    end

    -- Operații CRUD
    if @op = 'select'
    begin
        SELECT nume_antrenor, data_nasterii
        FROM Antrenori
        WHERE id_antrenor = @id
        print 'Select done'
    end
    else if @op = 'update'
    begin
        UPDATE Antrenori
        SET nume_antrenor = @nume_antrenor, data_nasterii = @data_nasterii
        WHERE id_antrenor = @id
        print 'Update done'
    end
    else if @op = 'delete'
    begin
        DELETE FROM Antrenori
        WHERE id_antrenor = @id
        print 'Delete done'
    end
    else if @op = 'insert'
    begin
        INSERT INTO Antrenori (nume_antrenor, data_nasterii)
        VALUES (@nume_antrenor, @data_nasterii)
        print 'Insert done'
    end
    else
        print 'Invalid command'
END
GO

-- Selectăm ligile care au mai mult de 10 echipe
CREATE OR ALTER VIEW v_Ligi_Considerabile AS
SELECT 
    L.nume_liga,
    O.nume_oras,
    L.numar_echipe
FROM Ligi L
INNER JOIN Oras O ON L.id_oras = O.id_oras
WHERE L.numar_echipe > 15
GO
CREATE NONCLUSTERED INDEX IDX_Ligi_numar_echipe_nume_oras
ON Ligi (numar_echipe, id_oras);
GO

CREATE NONCLUSTERED INDEX IDX_Ligi_id_oras_numar_echipe_nume_oras
ON Ligi (id_oras, numar_echipe)
INCLUDE (nume_liga);


SELECT * FROM v_Ligi_Considerabile
GO;


--antrenorii si numarul de victorii
CREATE OR ALTER VIEW v_Antrenori_Castigatori AS
SELECT 
    A.nume_antrenor,
    L.nume_liga,
    COUNT(LC.an_castigat) AS nr_castigate
FROM 
    LigiCastigate LC
INNER JOIN Antrenori A ON LC.id_antrenor = A.id_antrenor
INNER JOIN Ligi L ON LC.id_liga = L.id_liga
GROUP BY A.nume_antrenor, L.nume_liga 
GO
CREATE NONCLUSTERED INDEX IDX_LigiCastigate_antrenor_liga_castiguri
ON LigiCastigate (id_antrenor, id_liga, an_castigat);
GO

SELECT * FROM v_Antrenori_Castigatori

USE Lab1;
GO


select * from Ligi

select * from Oras


EXEC crud_Ligi
    @op = 'insert', 
    @id_liga = '11',   -- ID-ul ligii
    @id_oras = '10',   -- ID-ul orașului
    @nume_liga = 'Liga Profesionistă', 
    @numar_echipe = '18';

EXEC crud_Ligi
    @op = 'select', 
    @id_liga = '2',   -- ID-ul ligii pe care vrem să o citim
    @id_oras = '2',
    @nume_liga = 'Liga II',   -- Numele ligii nu este relevant la select
    @numar_echipe = '20';

EXEC crud_Ligi
    @op = 'update', 
    @id_liga = '5',
    @id_oras = '2',
    @nume_liga = 'Super Liga Profesionistă',
    @numar_echipe = '20';

EXEC crud_Ligi
    @op = 'delete', 
    @id_liga = '5',  -- ID-ul ligii pe care vrem să o ștergem
    @id_oras = '2',  -- Orașul asociat
    @nume_liga = 'Super Liga Profesionistă',
    @numar_echipe = '20';



EXEC crud_Ligi_Castigate
    @op = 'insert', 
    @id_antrenor = '3',    -- ID-ul antrenorului
    @id_liga = '4',        -- ID-ul ligii
    @an_castigat = '2023';

EXEC crud_Ligi_Castigate
    @op = 'select', 
    @id_antrenor = '3',    -- ID-ul antrenorului
    @id_liga = '4',        -- ID-ul ligii
    @an_castigat = '';

EXEC crud_Ligi_Castigate
    @op = 'update', 
    @id_antrenor = '3', 
    @id_liga = '4', 
    @an_castigat = '2024';

EXEC crud_Ligi_Castigate
    @op = 'delete', 
    @id_antrenor = '3', 
    @id_liga = '4',
    @an_castigat = '2024';



SELECT * FROM LigiCastigate

SELECT * FROM Ligi WHERE id_liga = 5;