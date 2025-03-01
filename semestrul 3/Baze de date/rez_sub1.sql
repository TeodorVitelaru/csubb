
create table Angajati
(
	id int primary key identity(1,1),
	numar varchar(100),
	nr_contract int
);

create table Mese
(
	numar int primary key identity(1,1),
	culoare varchar(100)
);

create table Meciuri
(
	id_meci int primary key identity(1,1),
	numar_masa int foreign key references Mese(numar),
	id_p1 int foreign key references Angajati(id),
	id_p2 int foreign key references Angajati(id),
	castigator int foreign key references Angajati(id)
);

create table Mutari
(
	id_mutari int primary key identity(1,1),
	id_meci int foreign key references Meciuri(id_meci),
	piese_mutata_de_la int Check(piese_mutata_de_la>0 and piese_mutata_de_la<7),
	piese_mutata_la int Check(piese_mutata_la>0 and piese_mutata_la<7),
);

create table Spectatori
(
	id_spectator int primary key identity(1,1),
	id_angajat int foreign key references Angajati(id),
	id_meci int foreign key references Meciuri(id_meci)

);
GO;

create or alter procedure premiu
@id_participant int
as
begin
	declare @puncte int
	set @puncte=0
	select @puncte=count(*) from Meciuri where castigator=@id_participant
	
	select @puncte=@puncte+count(*)*10 from Meciuri as M
	inner join Spectatori as S on M.id_meci=S.id_meci
	where M.id_p1=@id_participant or M.id_p2=@id_participant

	declare @nr_meciuri int
	set @nr_meciuri=0
	select @nr_meciuri=count(*) from Meciuri

	declare @participari int
	set @participari=0
	select count(*) from Meciuri as M
	inner join Spectatori as S on M.id_meci=S.id_meci
	where M.id_p1=@id_participant or M.id_p2=@id_participant

	declare @spectator int
	set @spectator=0
	select count(*) from Meciuri as M
	inner join Spectatori as S on M.id_meci=S.id_meci
	where M.id_p1!=@id_participant and M.id_p2!=@id_participant and S.id_spectator=@id_participant

	declare @puncte_pierdute int
	set @puncte_pierdute=(@nr_meciuri-@participari-@spectator)*10

	set @puncte=@puncte-@puncte_pierdute

	if @puncte < 0
		set @puncte=0

	return @puncte
end
go;

create or alter view DubleJucataor
as
	select A.numar, A.nr_contract, COUNT(*) as NumarDuble from Angajati as A
	inner join Meciuri as M on (M.id_p1=A.id or M.id_p2=A.id)
	inner join Mutari as Mu on M.id_meci=Mu.id_meci
	where A.nr_contract= 'ceva' and Mu.piese_mutata_de_la=piese_mutata_la
	group by 
		A.numar, A.nr_contract

go;

