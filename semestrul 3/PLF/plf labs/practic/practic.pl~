%diferenta(l1..ln, cif, tr)=
%=[], n=0
%=[l1-cif], daca n=1 si l1-cif>=0, setam tr=0
%=10+l1-cif, daca n=1, l1-cif<0, setam tr=1
%=l1-tr1 U diferenta(l2..ln, cif, tr1), daca l1-tr1>=0, atunci tr=0
%=l1-tr1 U diferenta(l2..ln, cif, tr1), daca l1-tr1<0, atunci tr=1
%diferenta(L:lista, C:int, F:int, R:list)
%(i,i,i,o)
diferenta([], _, _, []).
diferenta([H], C, 0, [Rez]):-
    Rez is H-C,
    Rez >= 0,
    !.
diferenta([H], C, 1, [Rez]):-
    !,
    Rez is 10+H-C.

diferenta([H|T], C, 0, [A|Rez]):-
    diferenta(T, C, Tr1, Rez),
    A is H-Tr1,
    A >=0,!.

diferenta([H|T], C, 1, [A|Rez]):-
    !,
    diferenta(T,C,Tr1, Rez),
    A is 10-H-Tr1.

%verifica daca incepe cu 0
%verif(L:list)
%(i)
verif([0|_]).

%elimina(l1..ln)= l2..ln
%elimina(L:list, R:list)
%(i, o)
elimina([_|T], T).


%main(L, C) =
%=diferenta(L,C,0), daca rezultatul intors nu contine 0
%=l1 - diferenta(L,C,0), altfel
%
%main(L:list, C:int, R:list)
%model de flux:  (i,i,o)
main(L, C, Rez):-
    diferenta(L, C, F, R),
    verif(R),
    !,
    elimina(R, Rez).
main(L,C,R):-
    diferenta(L,C,F,R).



