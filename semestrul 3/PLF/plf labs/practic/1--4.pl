%sub(l1...ln, E, L1..Lm)=
%=[], daca n=0
%=l1 + sub(l2...ln, E, L1...Lm), daca l1!=E
%=L..Lm + sub(l2..Ln, E, L1..Lm), daca l1=E

sub([], _, _, []).
sub([H|T], H, L1, [L1|R]):-
    !,
    sub(T, H, L1, R).
sub([H|T], E, L1, [H|R]):- sub(T, E, L1, R).


%elim(l1...ln, p, n1)=
%=l1+elim(l2...ln, p1, n1), daca p!=n1, p1=p+1
%=elim(l2...ln, p1, n1), daca p=n1, p1=p+1
%=[], daca n=0
elim([], _, _, []).
elim([H|T], P, N, [H|R]):-
    P \= N,
    !,
    P1 is P+1,
    elim(T, P1, N, R).
elim([H|T], P, P, R):-
    !,
    P1 is P + 1,
    elim(T, P1, P, R).
