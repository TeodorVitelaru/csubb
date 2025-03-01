%inter(l1..ln, L1..Lm)=
%=l, daca m=0
%=L, daca n=0
%=l1+inter(l2..ln, L1..Lm), daca l1<L1
%=L1+inter(l1..ln, L2..Lm), daca L1<l1

inter([], L1, L1).
inter(L, [], L).
inter([H|T], [H1|T1], [H|R]):-
    H < H1,
    !,
    inter(T, [H1|T1], R).
inter([H|T], [H1|T1], [H1|R]):-
    H > H1,
    !,
    inter([H|T], T1, R).

inter([H|T], [H1|T1], [H1|R]):-
    H = H1,
    !,
    inter(T, T1, R).
