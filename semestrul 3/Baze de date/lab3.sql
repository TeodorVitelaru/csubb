--modifica tipul unei coloane
use Lab1
GO
--modifica de la varhar la nvarchar
create or alter procedure ChangeNameTo_NVarChar
as
BEGIN
	alter table Jucatori
	alter column nume_juc NVARCHAR(100) NOT NULL
END
GO
--modifica de la nvarchar la varchar
create or alter procedure ChangeNameTo_Varchar
as
BEGIN
	alter table Jucatori
	alter column nume_juc Varchar(100) not null
END
GO


--adauga o contrangere de valoare implicita pentru un camp
--adaugam ca numarul de echipa sa fie implicit 15
create procedure AddDefaultValueToNumarEchipe
as
BEGIN
	ALTER TABLE Ligi
	ADD CONSTRAINT df_NumarEchipe DEFAULT 15 for numar_echipe
END
GO

create procedure RemoveDefaultValueToNumarEchipe
as
BEGIN
	alter table Ligi
	Drop constraint df_NumarEchipe
END
GO


--creea/sterge o tabela
create or alter procedure AddTariTable
as
BEGIN
	CREATE TABLE Tari
	(
		id_tara int not null primary key,
		nume_tara VARCHAR(20) NOT NULL,
	);
END
GO

create procedure DeleteTariTable
as
BEGIN
	drop table Tari
END
GO


--adauga un camp nou
create procedure AddTariPopulatie
as 
BEGIN
	alter table Tari
	add populatie INT
END
GO

create or alter procedure DeleteTariPopulatie
as
BEGIN
	ALTER TABLE Tari
	DROP COLUMN populatie
END
GO



--adauga contrangere pe cheie straina
create or alter procedure LinkTariToJucatori
as
begin
	alter table Tari
	add constraint fk_id_tara_ceva
	FOREIGN key (id_tara) references Jucatori(id_jucator)
end
GO

create or alter procedure RemoveConstraintTari
as
begin
	alter table Tari
	drop constraint fk_id_tara_ceva
end
go





CREATE TABLE VersionTable
(
	nr_versiune int default 0 not null
);

insert into VersionTable values (0)

create table DirectProcedures
(
	id_directProc int primary key,
	nume_proc varchar(200)
);

create table ReverseProcedures
(
	id_reverseProc int primary key,
	nume_proc varchar(200)
);


insert into DirectProcedures values
(1, 'ChangeNameTo_NVarChar'),
(2, 'AddDefaultValueToNumarEchipe'),
(3, 'AddTariTable'),
(4, 'AddTariPopulatie'),
(5, 'LinkTariToJucatori');

insert into ReverseProcedures values
	(1,'CharngeNameTo_Varchar'),
    (2,'RemoveDefaultValueToNumarEchipe'),
    (3,'DeleteTariTable'),
    (4,'DeleteTariPopulatie'),
    (5,'RemoveConstraintTari');


SELECT * FROM DirectProcedures
select * from ReverseProcedures
go

create or alter procedure main
@versiune int
as
begin
	if @versiune > 5
		BEGIN
			raiserror('Este prea mult', 16, 1)
			return;
		END
	declare @versiune_actuala as int
	select @versiune_actuala=nr_versiune from VersionTable
	print 'Versiune actuala este: ';
	print @versiune_actuala;
	print 'Versiunea ceruta este: '
	print @versiune

	declare @functie as varchar(100);

	if @versiune=@versiune_actuala
		begin
			print 'Suntem deja in aceaste versiune';
			return;
		end

	if @versiune > @versiune_actuala
		begin
			while @versiune_actuala+1 <= @versiune
				begin
					select @functie=nume_proc from DirectProcedures
					where id_directProc=@versiune_actuala+1
					print @functie
					exec @functie
					set @versiune_actuala=@versiune_actuala+1
				end
			update VersionTable
			set nr_versiune=@versiune
		end
	else if @versiune < @versiune_actuala
		begin
			
			while @versiune_actuala >= @versiune
				begin
					select @functie=nume_proc from ReverseProcedures
					where id_reverseProc=@versiune_actuala
					print @functie
					exec @functie
					set @versiune_actuala=@versiune_actuala-1
				end
			update VersionTable
			set nr_versiune=@versiune
		end

end


exec main 0

update VersionTable
set nr_versiune=0


