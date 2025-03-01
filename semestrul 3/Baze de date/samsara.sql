create table Comenzi
(
	id_comanda int primary key identity(1,1),
	adresa_livrare varchar(100),
	data_livrate date,
	id_client int foreign key references Clienti(id_client)
);

create table Clienti
(
	id_client int primary key identity(1,1),
	nume varchar(100),
	nr_telefon varchar(100),
);

create table Preparate
(
	id_preparat int primary key identity(1,1),
	denumire varchar(100),
	cantitate varchar(100),
	pret int
);

create table Comenzi_Preparate
(
	id int primary key identity(1,1),
	id_comanda int foreign key references Comenzi(id_comanda),
	id_preparat int foreign key references Preparate(id_preparat)
);

create table Ingrediente
(
	id_i int primary key identity(1,1),
	denumire varchar(100),
	calorii int
);

create table Preparate_Ingrediente
(
	id int primary key identity(1,1),
	id_preparat int foreign key references Preparate(id_preparat),
	id_ingredient int foreign key references Ingrediente(id_i)
);
GO;


create or alter procedure IngredientInterzis
@nume_ingredient varchar(100)
as
	declare @nr_comenzi_sterse int
	set @nr_comenzi_sterse=0

	declare @Comenzi_de_sters Table (id_comanda int)
	insert into @Comenzi_de_sters
	select distinct C.id_comanda from Comenzi as C
	inner join Comenzi_Preparate as CP on C.id_comanda=CP.id_comanda
	inner join Preparate as P on P.id_preparat=CP.id_preparat
	inner join Preparate_Ingrediente as PI on PI.id_preparat=P.id_preparat
	inner join Ingrediente as I on I.id_i=PI.id_ingredient
	where I.denumire=@nume_ingredient

	select @nr_comenzi_sterse=count(distinct C.id_comanda) from Comenzi as C
	inner join Comenzi_Preparate as CP on C.id_comanda=CP.id_comanda
	inner join Preparate as P on P.id_preparat=CP.id_preparat
	inner join Preparate_Ingrediente as PI on PI.id_preparat=P.id_preparat
	inner join Ingrediente as I on I.id_i=PI.id_ingredient
	where I.denumire=@nume_ingredient

	delete from Comenzi_Preparate
	where id_comanda IN (select id_comanda from @Comenzi_de_sters)

	delete from Comenzi
	where id_comanda in (select id_comanda from @Comenzi_de_sters)

	return @nr_comenzi_sterse


create or alter view ComandaBogdan
as
	select C.id_comanda, sum(P.pret) as Suma from Comenzi as C
	inner join Comenzi_Preparate as CP on CP.id_comanda=C.id_comanda
	inner join Preparate as P on CP.id_preparat=P.id_preparat
	inner join Clienti as Cl on Cl.id_client=C.id_client
	where Cl.nume='Bogdan Ioan'
	group by (id_comanda)
