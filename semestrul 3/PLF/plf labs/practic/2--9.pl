%sterge_con(l1..ln, f)=
%=[], n=0
%=l1, daca n=1 si f=0
%=[], daca n=1 si f=1
%=l1+sterge_con(l2..ln, f), daca l2 nu este l1+1
%=sterge(l2..ln, 1), daca l2=l1+1
%=sterge(l2..ln, 0), daca f=1 si l2!=l1+1
verif(A, B):-
    Aux is A+1,
    B = Aux.

sterge_con([], [], _):-!.
sterge_con([_], [], 1):-!.
sterge_con([H], [H], 0):-!.
sterge_con([A,B|[]], [], _):-
           verif(A,B),!.

sterge_con([A,B|T], R, _):-
    verif(A,B),
    !,
    sterge_con([B|T], R, 1).
sterge_con([H|T], R, 1):-
    !,
    sterge_con(T, R, 0).
sterge_con([H|T], [H|R], _):-
    sterge_con(T, R, 0).

face(L, R):-
    sterge_con(L, R, 0).


