%transform(l1...ln, L1...Lm)
%=l1+transform(l2...ln, l1+L1...Lm), daca l1 not in L
%=transform(l2...ln, l1+L1...Lm), daca l1 in L
%=[], daca n=0

apare(E, [E|_]):-!.
apare(E, [_|T]):-apare(E, T).

transform([], Acc, []).
transform([H|T], Acc, R):-
    apare(H, Acc),
    !,
    transform(T,Acc, R).
transform([H|T], Acc, [H|R]):-
    transform(T, [H|Acc], R).

%descompune(l1...ln,)
descompune([], [[], [], 0, 0]).
descompune([H|T], [[H|Pare], Impare, P1, I]):-
           0 is H mod 2,
           descompune(T, [Pare, Impare, P, I]),
           P1 is P + 1.
descompune([H|T], [Pare, [H|Impare], P, I1]):-
    1 is H mod 2,
    descompune(T, [Pare, Impare, P, I]),
    I1 is I + 1.


