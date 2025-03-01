%sort(l1..ln)=
%=[], daca n=0
%=insereaza(l1)+sort(l2..ln), altfel

%insereaza(T, l1..ln)
%=T, daca n=0
%=T + l1 +..+ln, daca T<=l1
%=l1 + insereaza(T, l2..ln), daca T>l1
insereaza(X, [], [X]).
insereaza(X, [H|T], [X,H|T]):-
    X =< H, !.
insereaza(X, [H|T], [H|R]):-
    insereaza(X, T, R).

sorteaza([], []).
sorteaza([H|T], R):-
    sorteaza(T, R1),
    insereaza(H, R1, R).
