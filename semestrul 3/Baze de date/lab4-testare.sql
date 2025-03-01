use Lab1;
GO;

insert into Tables(Name) values
('Antrenori'),
('Ligi'),
('LigiCastigate');
GO;


--un select
create or alter view vw_antrenori
as
select nume_antrenor from Antrenori
GO;

--antrenori ce au castigat
create or alter view vw_antrenori_ligiCastigate
as
select a.nume_antrenor from Antrenori a
inner join LigiCastigate lc on lc.id_antrenor=a.id_antrenor
inner join Ligi l on lc.id_liga = l.id_liga

--numele antrenorilor si numarul de ligi castigate
create or alter view  vw_antrenori_victorii
as
select a.nume_antrenor, count(lc.an_castigat) as ligi_castigate  from Antrenori a
left join LigiCastigate lc on a.id_antrenor=lc.id_antrenor
left join Ligi l on lc.id_liga=l.id_liga
group by(a.nume_antrenor)
GO;

insert into Views(Name) values
('vw_antrenori'),
('vw_antrenori_ligiCastigate'),
('vw_antrenori_victorii');
GO

insert into Tests(Name) values
('Insert10'),
('Insert100'),
('Insert1000'),
('Delete10'),
('Delete100'),
('Delete1000'),
('Run_View');
GO

select * from Tables

select * from TestTables


insert into TestTables(TestID, TableID, NoOfRows, Position) values
(1, 1, 10, 1),
(1, 2, 10, 2),
(1, 3, 10, 3),

(2, 1, 100, 1),
(2, 2, 100, 2),
(2, 3, 100, 3),

(3, 1, 1000, 1),
(3, 2 ,1000, 2),
(3, 3, 1000, 3),

(4, 1, 10, 3),
(4, 2, 10, 2),
(4, 3, 10, 1),

(5, 1, 100, 3),
(5, 2, 100, 2),
(5, 3, 100, 1),

(6, 1, 1000, 3),
(6, 2 ,1000, 2),
(6, 3, 1000, 1)
GO


insert into TestViews(TestId, ViewId) values
(7,1),
(7,2),
(7,3)
GO

create or alter procedure InsertAntrenori @size int
as
begin
	declare @id int
	declare @nume varchar(100)
	declare @data_nasterii varchar(100)
	declare @cnt int
	declare @last int

	set @nume= 'NumeAntrenor'
	set @data_nasterii = '2000-02-02'
	set @id=2000
	set @cnt = 1

	while @cnt <= @size
		begin
			set @id=2000+@cnt
			select @last=max(A.id_antrenor) from dbo.Antrenori A
			if @last > 2000
				set @id = @last + 1
			set IDENTITY_INSERT Antrenori ON
				insert into Antrenori(id_antrenor, nume_antrenor, data_nasterii)
				values (@id, @nume, @data_nasterii)
			set IDENTITY_INSERT Antrenori OFF
			set @cnt=@cnt+1
		end
end
GO

create or alter procedure DeleteAntrenori @size int
as
begin
	declare @id int
	declare @cnt int
	declare @last int

	set @id=2000
	set @cnt=@size

	while @cnt > 0
		begin
			set @id = 2000 + @cnt
			select @last=max(A.id_antrenor) from dbo.Antrenori A
			if @id < @last
				set @id=@last
			delete from Antrenori where id_antrenor=@id
			set @cnt=@cnt-1
		end
end
GO

create or alter procedure InsertLigi @size int
as
begin
	declare @id int
	declare @id_oras int
	declare @nume_liga varchar(100)
	declare @numar_echipe int
	declare @cnt int
	declare @last int

	set @nume_liga='NumeLiga'
	set @numar_echipe=13
	set @id_oras=1
	set @id=2000
	set @cnt = 1

	while @cnt <= @size
		begin
			set @id=2000+@cnt
			select @last =max(L.id_liga) from dbo.Ligi L
			if @last > 2000
				set @id=@last+1
			set IDENTITY_INSERT Ligi on
				insert into Ligi(id_liga, id_oras, nume_liga, numar_echipe)
				values (@id, @id_oras, @nume_liga, @numar_echipe)
			set IDENTITY_INSERT Ligi off
			set @cnt=@cnt+1
		end
end
GO

create or alter procedure DeleteLigi @size int
as
begin
	declare @id int
	declare @cnt int
	declare @last int

	set @id=2000
	set @cnt=@size

	while @cnt > 0
		begin
			SET @id = 2000 + @cnt
			SELECT @last = MAX(L.id_liga) FROM dbo.Ligi L
			IF @id < @last
				SET @id = @last
			DELETE FROM Ligi WHERE id_liga = @id
			SET @cnt = @cnt - 1
		end
end
GO

create or alter procedure InsertLigiCastigate @size int
as
begin
	declare @cnt int
	set @cnt = @size
	exec InsertAntrenori @size

	declare @id_antrenor int
	declare @nume_antrenor varchar(100)
	declare @data_nasterii varchar(100)

	declare CursorAntrenor cursor scroll for
		select id_antrenor, nume_antrenor, data_nasterii from Antrenori
	open CursorAntrenor

	fetch last from CursorAntrenor into @id_antrenor, @nume_antrenor, @data_nasterii

	while @cnt > 0 and @@FETCH_STATUS=0
	begin
		insert into LigiCastigate(id_antrenor, id_liga)
		values (@id_antrenor, 1)
		fetch prior from CursorAntrenor into @id_antrenor, @nume_antrenor, @data_nasterii
		set @cnt = @cnt -1
	end
	close CursorAntrenor
	deallocate CursorAntrenor

end
GO

create or alter procedure DeleteLigicastigate @size int
as
begin
	declare @id int
	declare @cnt int
	declare @last int
	set @id = 2000
	set @cnt=@size

	while @cnt > 0
	begin
		set @id = 2000+@cnt
		select @last =max(LC.id_antrenor) from dbo.LigiCastigate LC
		if @id < @last
			set @id=@last
		delete from LigiCastigate where id_antrenor=@id and id_liga=1;
		set @cnt=@cnt-1
	end
end
GO

create or alter procedure Insert10 @Table varchar(100)
as
begin
	if @Table = 'Antrenori'
		exec InsertAntrenori 10
	if @Table = 'Ligi'
		exec InsertLigi 10
	if @Table = 'LigiCastigate'
		exec InsertLigiCastigate 10
end
GO

create or alter procedure Insert100 @Table varchar(100)
as
begin
	if @Table = 'Antrenori'
		exec InsertAntrenori 100
	if @Table = 'Ligi'
		exec InsertLigi 100
	if @Table = 'LigiCastigate'
		exec InsertLigiCastigate 100
end
GO

create or alter procedure Insert1000 @Table varchar(100)
as
begin
	if @Table = 'Antrenori'
		exec InsertAntrenori 1000
	if @Table = 'Ligi'
		exec InsertLigi 1000
	if @Table = 'LigiCastigate'
		exec InsertLigiCastigate 1000
end
GO

create or alter procedure Delete10 @Table varchar(100)
as
begin
	if @Table = 'Antrenori'
		exec DeleteAntrenori 10
	if @Table = 'Ligi'
		exec DeleteLigi 10
	if @Table = 'LigiCastigate'
		exec InsertLigiCastigate 10
end
GO

create or alter procedure Delete100 @Table varchar(100)
as
begin
	if @Table = 'Antrenori'
		exec DeleteAntrenori 100
	if @Table = 'Ligi'
		exec DeleteLigi 100
	if @Table = 'LigiCastigate'
		exec InsertLigiCastigate 100
end
GO

create or alter procedure Delete1000 @Table varchar(100)
as
begin
	if @Table = 'Antrenori'
		exec DeleteAntrenori 1000
	if @Table = 'Ligi'
		exec DeleteLigi 1000
	if @Table = 'LigiCastigate'
		exec InsertLigiCastigate 1000
end
GO

create or alter procedure Run_View @View Varchar(100)
as
begin
	if @View = 'Antrenori'
		select * from vw_antrenori
	if @View = 'Ligi'
		select * from vw_antrenori_ligiCastigate
	if @View = 'LigiCastigate'
		select * from vw_antrenori_victorii
end
GO

create or alter procedure TestAll @Table varchar(50)
as
begin
		DECLARE @date1 DATETIME
		DECLARE @date2 DATETIME
		DECLARE @date3 DATETIME
		DECLARE @text NVARCHAR(500)

		DECLARE @insert VARCHAR(20)
		DECLARE @delete VARCHAR(20)		
		DECLARE @size INT
		DECLARE @id INT

		set @size = 10
		set @insert = case @size
						when 10 then 'Insert10'
						when 100 then 'Insert100'
						when 1000 then 'Insert1000'
					  end
		set @delete = case @size
						when 10 then 'Delete10'
						when 100 then 'Delete100'
						when 1000 then 'Delete1000'
					  end
		if @Table = 'Antrenori'
		begin
			set @date1 = GETDATE()
			exec (@insert + ' Antrenori')
			exec (@delete + ' Antrenori')
			set @date2= GETDATE()
			exec Run_View 'Antrenori'
			set @date3=GETDATE()
			set @text = @insert + N' ' + @delete + ' view: ' + @Table 
			insert into TestRuns values (@text, @date1, @date3)
			select @id=max(T.TestRunID) from dbo.TestRuns T
			insert into TestRunTables values (@id,1,@date1,@date2)
			INSERT INTO TestRunViews VALUES (@id,1,@date2,@date3)
		end
		if @Table = 'Ligi'
		begin
			set @date1 = GETDATE()
			exec (@insert + ' Ligi')
			exec (@delete + ' Ligi')
			set @date2= GETDATE()
			exec Run_View 'Ligi'
			set @date3=GETDATE()
			set @text = @insert + N' ' + @delete + ' view: ' + @Table 
			insert into TestRuns values (@text, @date1, @date3)
			select @id=max(T.TestRunID) from dbo.TestRuns T
			insert into TestRunTables values (@id,2,@date1,@date2)
			INSERT INTO TestRunViews VALUES (@id,2,@date2,@date3)
		end
		if @Table = 'LigiCastigate'
		begin
			set @date1 = GETDATE()
			exec (@insert + ' LigiCastigate')
			exec (@delete + ' LigiCastigate')
			set @date2= GETDATE()
			exec Run_View 'LigiCastigate'
			set @date3=GETDATE()
			set @text = @insert + N' ' + @delete + ' view: ' + @Table 
			insert into TestRuns values (@text, @date1, @date3)
			select @id=max(T.TestRunID) from dbo.TestRuns T
			insert into TestRunTables values (@id,3,@date1,@date2)
			INSERT INTO TestRunViews VALUES (@id,3,@date2,@date3)
		end

end
GO


create or alter procedure main
as
begin
	declare @cnt int
	select @cnt=count(*) from Tables
	declare @name varchar(20)

	declare CursorTable cursor scroll for
		select Name From Tables;

	open CursorTable;
		fetch last from CursorTable into @name

	while @cnt > 0 and @@FETCH_STATUS = 0
	begin
		exec TestAll @name
		print @name
		fetch prior from CursorTable into @name
		set @cnt=@cnt-1
	end

	close Cursortable;
	deallocate CursorTable;
end
GO

exec main

select * from Views

SELECT * FROM TestRunTables		

SELECT * from TestRunViews

SELECT * from TestRuns
