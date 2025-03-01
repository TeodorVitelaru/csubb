%succesor(l1..ln, t)=
%=[], n=0
%=l1+1, daca n=1, l1<=8, t=0
%=0, daca n=1, l1=9, t=1
%=(l1+t1) U succesor(l2..ln, t1), t=0
%=0 U succesor(l2,..ln, 1),  t=1
succesor([], _, []).
succesor([9], 1, [0]):-!.
succesor([H], 0, [R]):-
    R is H + 1.
succesor([9|T], 1, [0|R]):-
    !,
    succesor(T,1,R).
succesor([H|T], 0, [New|R]):-
    succesor(T, Tr1, R),
    New is H+Tr1.

