%diferenta([l1...ln], [L1..LM])=
%=l1 U diferenta([l2...ln], [L1..LM]), daca l1 not in L
%=diferenta(([l2...ln], [L1..LM]), daca l1 este in L
%= [], daca n=0
%diferenta(L:list, L1:list, R:list)
%model de flux: (i,i,o)

diferenta([], _, []).
diferenta([H|T], L1, R):-
    apare(H, L1),
    !,
    diferenta(T, L1, R).
diferenta([H|T], L1, [H|R]):-
    diferenta(T, L1, R).

%model matematic:
%apare(E, [l1...ln])=
%=1, daca E=l1
%=0, daca n=0
%=apare(E, [l2..ln]), daca n!=0 si E!=l1

apare(E, [E|_]).
apare(E, [_|T]):-apare(E, T).



%adaugare([l1...ln])=
%=[], daca n=0
%=l1+1+adaugare()

adaugare([], []).
adaugare([H|T], [H,1|Rez]):-
    0 is H mod 2,
    !,
    adaugare(T, Rez).
adaugare([H|T], [H|Rez]):-adaugare(T,Rez).
