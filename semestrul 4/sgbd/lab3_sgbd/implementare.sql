-- Funcție de validare pentru numele ligii
CREATE or alter FUNCTION uf_ValidateNumeLiga (@nume_liga VARCHAR(255)) RETURNS INT AS
BEGIN
    DECLARE @return INT;
    SET @return = 0;
    IF ((ASCII(LEFT(@nume_liga, 1)) BETWEEN 65 AND 90) AND LEN(@nume_liga) > 0)
        SET @return = 1;
    RETURN @return;
END;
GO;

-- Funcție de validare pentru numărul de echipe
CREATE FUNCTION uf_ValidateNumarEchipe (@numar_echipe INT) RETURNS INT AS
BEGIN
    DECLARE @return INT;
    SET @return = 0;
    IF (@numar_echipe > 0)
        SET @return = 1;
    RETURN @return;
END;
GO;

-- Funcție de validare pentru numele antrenorului
CREATE FUNCTION uf_ValidateNumeAntrenor (@nume_antrenor VARCHAR(255)) RETURNS INT AS
BEGIN
    DECLARE @return INT;
    SET @return = 0;
    IF (@nume_antrenor LIKE '[A-Z]%' AND LEN(@nume_antrenor) > 0)
        SET @return = 1;
    RETURN @return;
END;
GO;

-- Funcție de validare pentru data nașterii antrenorului
CREATE FUNCTION uf_ValidateDataNasterii (@data_nasterii DATE) RETURNS INT AS
BEGIN
    DECLARE @return INT;
    SET @return = 0;
    IF (@data_nasterii < GETDATE())
        SET @return = 1;
    RETURN @return;
END;
GO;

-- Tabelul pentru logare
CREATE TABLE LogTable (
    Lid INT IDENTITY PRIMARY KEY,
    TypeOperation VARCHAR(50),
    TableOperation VARCHAR(50),
    ExecutionDate DATETIME
);
GO;

CREATE or alter PROCEDURE InsertLigiAntrenori (
    @nume_liga VARCHAR(255),
    @id_oras INT = 1,  -- Valoare implicită 1 pentru id_oras
    @numar_echipe INT,
    @nume_antrenor VARCHAR(255),
    @data_nasterii DATE,
    @an_castigat INT
)
AS
BEGIN
    BEGIN TRANSACTION;  -- Începem tranzacția

    BEGIN TRY
        -- Validarea numelui ligii
        IF (dbo.uf_ValidateNumeLiga(@nume_liga) <> 1)
        BEGIN
            RAISERROR('Numele ligii trebuie să înceapă cu literă mare.', 16, 1);
        END

        -- Validarea numărului de echipe
        IF (dbo.uf_ValidateNumarEchipe(@numar_echipe) <> 1)
        BEGIN
            RAISERROR('Numărul de echipe trebuie să fie pozitiv.', 16, 1);
        END

        -- Validarea numelui antrenorului
        IF (dbo.uf_ValidateNumeAntrenor(@nume_antrenor) <> 1)
        BEGIN
            RAISERROR('Numele antrenorului trebuie să înceapă cu literă mare.', 16, 1);
        END

        -- Validarea datei nașterii antrenorului
        IF (dbo.uf_ValidateDataNasterii(@data_nasterii) <> 1)
        BEGIN
            RAISERROR('Data nașterii trebuie să fie în trecut.', 16, 1);
        END

        -- Inserăm în tabelul ligi
        INSERT INTO Ligi (id_oras, nume_liga, numar_echipe)
        VALUES (@id_oras, @nume_liga, @numar_echipe);

        -- Obținem ID-ul ligii inserate
        DECLARE @id_liga INT = SCOPE_IDENTITY();  -- Preluăm ID-ul ligii

        -- Inserăm în tabelul antrenori
        INSERT INTO Antrenori (nume_antrenor, data_nasterii)
        VALUES (@nume_antrenor, @data_nasterii);

        -- Obținem ID-ul antrenorului inserat
        DECLARE @id_antrenor INT = SCOPE_IDENTITY();  -- Preluăm ID-ul antrenorului

        -- Inserăm în tabelul de legătură ligi_castigate
        INSERT INTO LigiCastigate (id_antrenor, id_liga, an_castigat)
        VALUES (@id_antrenor, @id_liga, @an_castigat);

        -- Dacă totul a mers bine, facem commit
        COMMIT;

        -- Logăm operațiile
        INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
        VALUES ('INSERT', 'Ligi, Antrenori, LigiCastigate', GETDATE());

        PRINT 'Operație finalizată cu succes!';

    END TRY

    BEGIN CATCH
        -- Dacă apare vreo eroare, facem rollback
		IF @@TRANCOUNT > 0
           ROLLBACK TRAN;

        -- Logăm eroarea
        INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
        VALUES ('ERROR', 'Ligi, Antrenori, Ligi Castigate', GETDATE());

        PRINT ERROR_MESSAGE();
    END CATCH
END;
go;

EXEC InsertLigiAntrenori 
    @nume_liga = 'Asd', 
    @numar_echipe = 2000, 
    @nume_antrenor = 'Maria Ionescu', 
    @data_nasterii = '1990-05-20', 
    @an_castigat = 2022;

select * from LogTable

select * from Ligi
select * from Antrenori
GO;


CREATE or alter PROCEDURE InsertLigiAntrenoriCuRollbackSelectiv
    @nume_antrenor VARCHAR(100),
    @data_nasterii DATE,
    @nume_liga VARCHAR(100),
    @numar_echipe INT,
    @an_castigat INT
AS
BEGIN
    DECLARE @id_antrenor INT, @id_liga INT

    -- TRANZACȚIA 1: INSERARE ANTRENOR
    BEGIN TRY
        BEGIN TRAN

        -- Validarea numelui antrenorului
        IF (dbo.uf_ValidateNumeAntrenor(@nume_antrenor) <> 1)
        BEGIN
            RAISERROR('Numele antrenorului trebuie să înceapă cu literă mare.', 16, 1);
        END

        -- Validarea datei nașterii antrenorului
        IF (dbo.uf_ValidateDataNasterii(@data_nasterii) <> 1)
        BEGIN
            RAISERROR('Data nașterii trebuie să fie în trecut.', 16, 1);
        END

        INSERT INTO Antrenori(nume_antrenor, data_nasterii)
        VALUES (@nume_antrenor, @data_nasterii)

        SET @id_antrenor = SCOPE_IDENTITY()

        -- LOG
        INSERT INTO LogTable(TypeOperation, TableOperation, ExecutionDate)
        VALUES ('INSERT', 'Antrenori', GETDATE())

        COMMIT TRAN
    END TRY
    BEGIN CATCH
        IF @@TRANCOUNT > 0 ROLLBACK TRAN
        PRINT 'Eroare la inserarea antrenorului: ' + ERROR_MESSAGE()
        INSERT INTO LogTable(TypeOperation, TableOperation, ExecutionDate)
		VALUES ('ERROR: ' + ERROR_MESSAGE(), 'Antrenori', GETDATE());
		RETURN
    END CATCH

    -- TRANZACȚIA 2: INSERARE LIGĂ
    BEGIN TRY
        BEGIN TRAN

        -- Validarea numelui ligii
        IF (dbo.uf_ValidateNumeLiga(@nume_liga) <> 1)
        BEGIN
            RAISERROR('Numele ligii trebuie să înceapă cu literă mare.', 16, 1);
        END

        -- Validarea numărului de echipe
        IF (dbo.uf_ValidateNumarEchipe(@numar_echipe) <> 1)
        BEGIN
            RAISERROR('Numărul de echipe trebuie să fie pozitiv.', 16, 1);
        END

        INSERT INTO Ligi(nume_liga, numar_echipe, id_oras)
        VALUES (@nume_liga, @numar_echipe, 1) -- presupunem id_oras default 1

        SET @id_liga = SCOPE_IDENTITY()

        -- LOG
        INSERT INTO LogTable(TypeOperation, TableOperation, ExecutionDate)
        VALUES ('INSERT', 'Ligi', GETDATE())

        COMMIT TRAN
    END TRY
    BEGIN CATCH
        IF @@TRANCOUNT > 0 ROLLBACK TRAN
        PRINT 'Eroare la inserarea ligii: ' + ERROR_MESSAGE()
        INSERT INTO LogTable(TypeOperation, TableOperation, ExecutionDate)
		VALUES ('ERROR: ' + ERROR_MESSAGE(), 'Ligi', GETDATE());
	
		RETURN
    END CATCH

    -- TRANZACȚIA 3: INSERARE ÎN LigiCastigate
    BEGIN TRY
        BEGIN TRAN

        INSERT INTO LigiCastigate(id_antrenor, id_liga, an_castigat)
        VALUES (@id_antrenor, @id_liga, @an_castigat)

        -- LOG
        INSERT INTO LogTable(TypeOperation, TableOperation, ExecutionDate)
        VALUES ('INSERT', 'LigiCastigate', GETDATE())

        COMMIT TRAN
    END TRY
    BEGIN CATCH
        IF @@TRANCOUNT > 0 ROLLBACK TRAN
        PRINT 'Eroare la inserarea în LigiCastigate: ' + ERROR_MESSAGE()
        INSERT INTO LogTable(TypeOperation, TableOperation, ExecutionDate)
		VALUES ('ERROR: ' + ERROR_MESSAGE(), 'LigiCastigate', GETDATE());
	
		RETURN
    END CATCH
END

GO;

EXEC InsertLigiAntrenoriCuRollbackSelectiv
    'Andrei Muresan', '1984-11-10', 'Liga Profesionista', 18, 2018
GO;

select * from LogTable;

EXEC InsertLigiAntrenoriCuRollbackSelectiv
    'Ion Barbu', '1990-05-05', 'Liga Națională', -2, 2019