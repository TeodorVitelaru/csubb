%elimin(l1..ln, e, ap)=
%=[], daca n =0
%=l1 + elimin(l2..ln, e, ap), daca l1!=e
%=elimin(l2..ln, e, ap1), daca l1=e, ap1=ap+1
elimin([], _, _, []):-!.
elimin([E|T], E, Ap, R):-
    Ap1 is Ap+1,
    Ap1 =<3,
    !,
    elimin(T, E, Ap1, R).
elimin([H|T], E, Ap, [H|R]):-
    elimin(T, E, Ap, R).

main(L, E, R):-
    elimin(L, E, 0, R).
