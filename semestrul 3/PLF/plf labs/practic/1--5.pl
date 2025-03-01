%sterge(l1..ln, e)=
%=[], n=0
%=l1+sterge(l2..ln), daca l1=e
%=sterge(l2..ln), daca l1!=e
sterge([], _, []).
sterge([H|T], H, R):-
    !,
    sterge(T, H, R).
sterge([H|T], E, [H|R]):-sterge(T, E, R).


apare(E, [E|_]):-!.
apare(E, [_|T]):-apare(E, T).

%aparitii(e, l1...ln)=
%=0, daca n=0
%=1+aparitii(e, l2..ln), daca l1=e
%=aparitii(e, l2..ln), daca l1!=e
aparitii(_, [], 0):-!.
aparitii(E, [E|T], C):-!,
    aparitii(E, T, C1),
    C is C1+1.
aparitii(E, [_|T], C):-aparitii(E, T, C).

%modif(l1..ln)=
%=[], daca n=0
%=[l1, aparitii(l1)] + modif(l2...ln), daca n!=0
modif(_,[], [], _).
modif(L,[H|T], R, Aux):-
    apare(H, Aux),
    !,
    modif(L,T,R, Aux).
modif(L,[H|T], [[H,C]|R], Aux):-
    aparitii(H, L, C),
    modif(L, T, R, [H|Aux]).




