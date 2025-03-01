%produs(l1..ln, e, t)=
%=[], n=0
%=(l1*e)%10, daca n=1, t=(l1*e) // 10
%=(t1+l1*e)%10 U produs(l2..ln, t1), t=(t1+l1*e)//10
produs([], _, 0, []).
produs([H], E, Tr, [Rez]):-
    Rez is (H*E) mod 10,
    Tr is (H*E) // 10,!.
produs([H|T], E, Tr, [El|R]):-
    !,
    produs(T, E, Tr1, R),
    El is (Tr1+H*E) mod 10,
    Tr is (Tr1+H*E)//10.

prod_final(L, E, F):-
    produs(L,E,Tr,Rez),
    Tr \= 0,
    !,
    apel(Tr, Rez1),
    concat(Rez1,Rez, F).

prod_final(L,E,Rez):-
    produs(L,E,_,Rez).

%lipeste prima lista de a doua
concat([], Rez, Rez).
concat([H|T], R, [H|Rez]):-concat(T, R, Rez).

%Pune intr o lista cifrele unui numar in ordine.
important(0, Res, Res):-!.
important(N, Acc, Res):-
    R is N mod 10,
    Cat is N // 10,
    important(Cat, [R|Acc], Res).
apel(N, Res):-
    important(N, [], Res).


