%suma(l1..ln, L1..Lm, f)=
%=(l1+L1)mod10, daca m=n=1 si setam f=(l1+L1)/10
%=(l1+f)+suma(l2..ln, L1..Lm, f), daca n>m
%=(L1+f)+suma(l1..ln, L2..Lm, f), daca n>m
%=(l1+L1+f)mod10+suma(l2..ln, L2..Lm,f)
%=f+suma(), daca F!=0

%suma(L:list, L1:list, N:int, M:int, R:int)
dif_lungime1([_|_], []):-!.
dif_lungime1([_|T1], [_|T2]):-
    dif_lungime1(T1,T2).

dif_lungime2([], [_|_]):-!.
dif_lungime2([_|T1], [_|T2]):-
    dif_lungime2(T1,T2).


suma([H|T], L1, [E|R], F):-
    dif_lungime1([H|T], L1),
    !,
    suma(T, L1, R, F1),
    E is (H+F1) mod 10,
    F is (H+F1)//10.

suma(L, [H|T], [E|R], F):-
    dif_lungime2(L, [H|T]),
    !,
    suma(L,T,R,F1),
    E is (H+F1) mod 10,
    F is (H+F1)//10.

suma([H|T], [H1|T1], [Rasp|R], F):-
    suma(T,T1,R,F1),
    Rasp is (H+H1+F1) mod 10,
    F is (H+H1+F1)//10.

suma([H], [H1], [Rez], F):-
    Rez is (H+H1) mod 10,
    F is (H+H1)//10.

main(L, L1, [F|R]):-
    suma(L, L1, R, F).


