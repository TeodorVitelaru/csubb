CREATE DATABASE Lab1;
GO
USE Lab1

create table Oras
(
id_oras int primary key identity,
nume_oras varchar(100),
capacitate_oras int
);

create table Ligi
(
id_liga int primary key identity,
id_oras int foreign key(id_oras) references Oras(id_oras),
nume_liga varchar(100), 
numar_echipe int,
);

create table Stadioane
(
id_stadion int primary key identity,
nume_stadion VARCHAR(100),
capacitate_stadion int,
id_oras int foreign key(id_oras) references Oras(id_oras)
);

create table Companii
(
id_companie int primary key identity,
nume_companie varchar(100),
cifra_afaceri int
);

create table Sponsori
(
id_sponsor INT PRIMARY KEY identity,
suma int,
id_companie int foreign key(id_companie) references Companii(id_companie),
);


create table Antrenori
(
id_antrenor int primary key identity,
nume_antrenor varchar(100),
data_nasterii varchar(100)
);

create table Echipe
(
id_echipa INT primary key identity,
nume_echipa VARCHAR(100),
data_deschidere VARCHAR(100),
id_sponsor int foreign key(id_sponsor) references Sponsori(id_sponsor),
id_stadion int foreign key(id_stadion) references Stadioane(id_stadion),
id_antrenor int foreign key(id_antrenor) references Antrenori(id_antrenor)
);

create table Jucatori
(id_jucator INT PRIMARY KEY IDENTITY,
nume_juc VARCHAR(100) NOT NULL,
prenume_juc VARCHAR(100) not null,
id_echipa int foreign key(id_echipa) references Echipe(id_echipa)
);

create table Pozitii
(
id_pozitie int primary key identity,
id_jucator int foreign key(id_jucator) references Jucatori(id_jucator),
nume_pozitie VARCHAR(100)
);

create table Oferte
(
id_oferta int primary key identity,
id_jucator int foreign key(id_jucator) references Jucatori(id_jucator),
id_echipa int foreign key(id_echipa) references Echipe(id_echipa),
suma_oferta int
);

create table Colaborari
(
id_colab int primary key identity,
nume_brand varchar(100) not null,
id_jucator int foreign key(id_jucator) references Jucatori(id_jucator),
durata_contract int
);

create table LigiCastigate
(
id_liga_castigata int primary key identity,
id_antrenor int foreign key(id_antrenor) references Antrenori(id_antrenor),
id_liga int foreign key(id_liga) references Ligi(id_liga),
an_castigat int
);
alter table LigiCastigate
add an_castigat int



