% Lista de pronosticuri posibile: 1, 2, x
pronostic(1).
pronostic(2).
pronostic(x).


%model matematic: generare_comb(P, C)=
%1.pronostic[E], daca p=4, E!=x,
%2.pronostic[E], daca p=4, E=x, C+1<=2
%3.pronostic(E) U generare_comb(P+1, C1, Rest), daca E!=x, C1=C
%4.pronostic(E) U generare_comb(P+1, C1, Rest), daca E=x, C1=C+1, C1<=2
%5.pronostic(E),     daca P=3, E!=2, C<=2
generare_comb(4, C, [E]):-
    pronostic(E),
    update_count(E, C, NC),
    NC =< 2,
    E \= 2.

generare_comb(P,C,[E|R]):-
    P<4,
    pronostic(E),
    update_count(E, C, NC),
    NC =< 2,
    P1 is P + 1,
    generare_comb(P1, NC, R).


%update_count(E:pronostic, C:int, NC:int)
%model de flux: (i,i,o)
%model matematic: update_count(e, c)=
%=c+1, daca e=x
%=c, daca e!=x
update_count(x, C, NC):-
    NC is C + 1.
update_count(E, C, C):-
    E \= x.

%model de flux: (o)
%model matematic: main()=generare(0, 0)
main(Rez):-
    findall(L, generare_comb(0,0,L), Rez),
    maplist(writeln, Rez).

