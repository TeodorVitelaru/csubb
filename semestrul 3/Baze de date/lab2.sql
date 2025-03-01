--afiseaza toate echipele din Cluj Napoca
select e.nume_echipa from Echipe e
inner join Stadioane s on e.id_stadion = s.id_stadion
inner join Oras o on s.id_oras = o.id_oras
where o.nume_oras  = 'Cluj-Napoca'

--numele antrenorilor care au castigat ligi in Liga IV
select a.nume_antrenor from Antrenori a
inner join LigiCastigate lc on lc.id_antrenor=a.id_antrenor
inner join Ligi l on lc.id_liga = l.id_liga
where l.nume_liga like 'Liga IV%'

--afiseaza orassul si capacitatea totala a stadionaelor mai mare de 20000 din orase care incep cu C
select o.nume_oras, sum(s.capacitate_stadion) as capacitate from Stadioane s
join Oras o on s.id_oras = o.id_oras
where o.nume_oras like 'C%'
group by o.nume_oras
having sum(s.capacitate_stadion) > 20000

--numele antrenorilor si numarul de ligi castigate
select a.nume_antrenor, count(lc.an_castigat) as ligi_castigate  from Antrenori a
left join LigiCastigate lc on a.id_antrenor=lc.id_antrenor
left join Ligi l on lc.id_liga=l.id_liga
group by(a.nume_antrenor)

--afiseaza suma si jucatorul care a primit oferta mai mare de 3000
--daca jucatorul are mai multe oferte, se va afisa una
select distinct j.nume_juc, o.suma_oferta from Jucatori j
join Oferte o on j.id_jucator=o.id_jucator
join Echipe e on e.id_echipa=o.id_echipa
where o.suma_oferta > 3000

--afiseaza numarul de colaborari active
--pe care le au companiile cu jucatorii de pe pozitia Mijlocas
select c.nume_brand, count(*) as numar_colaborati from Colaborari c
inner join Jucatori j on j.id_jucator=c.id_jucator
inner join Pozitii p on j.id_jucator=p.id_jucator
where p.nume_pozitie LIKE 'Mijlocas'
group by(c.nume_brand)

--orasele care au mai mult de un stadion
select o.nume_oras, count(o.nume_oras) from Stadioane s
inner join Oras o on s.id_oras=o.id_oras
group by(o.nume_oras)
having count(*) > 1

--cifra de afaceri a companiilor
--care sponsorizeaza echipe in ordine crescatoare
select distinct c.cifra_afaceri, c.nume_companie from Companii c
inner join Sponsori s on c.id_companie=s.id_companie
inner join Echipe e on e.id_sponsor = s.id_sponsor

--afiseaza echipele, orasele si numele antrenorilor
select e.nume_echipa, o.nume_oras, a.nume_antrenor from Echipe e
inner join Stadioane s on s.id_stadion=e.id_stadion
inner join Oras o on o.id_oras=s.id_oras
inner join Antrenori a on a.id_antrenor=e.id_antrenor