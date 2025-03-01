%inloc(l1..ln,e,L1..Lm)=
%=[], daca n=0
%=l1+inloc(l2..ln,e,L1..Lm), daca l1!=e
%=l1+L1+..+Lm+inloc(l2..ln,e,L1..Lm), daca l1=e

inloc([], _, _, []):-!.
inloc([H|T], E, L1, [H|R]):-
    H \= E,
    !,
    inloc(T, E, L1, R).
inloc([H|T], E, L1, R1):-
    H = E,
    parcurge(L1, R, R1),
    inloc(T, E, L1, R).

%parcurge(l1..ln, L1..Lm)=
%=L, daca n=0
%=l1+parcurge(l2..ln, L1..Lm)
parcurge([], L, L).
parcurge([H|T], L1, [H|R]):-
    parcurge(T, L1, R).
