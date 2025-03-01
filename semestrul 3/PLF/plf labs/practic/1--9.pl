%inter(l1...ln, L1..Lm)=
%[], daca n=0
%[], daca m=0
%l1+inter(l2..ln, L1..Lm), daca l1 nu apare in L
%inter(l2..ln, L1...Lm), daca l1 apare in L
inter([], _, []):-!.
inter(_, [], []):-!.
inter([H|T], L, [H|R]):-
    apare(H, L),
    !,
    inter(T, L, R).
inter([_|T], L, R):-inter(T, L, R).

apare(E, [E|_]):-!.
apare(E, [H|T]):-apare(E, T).

%construire(m, n)=
%=n, daca m=n
%=m U construire(m+1, n)
const(N,N,[N]):-!.
const(M, N, [M|R]):-
    M1 is M+1,
    const(M1, N, R).
