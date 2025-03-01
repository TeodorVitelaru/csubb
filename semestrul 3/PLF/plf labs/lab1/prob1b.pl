%add_one_after_even(L:lista, Rez:lista)
%L -lista initiala
%R - lista rezultata dupa adaufarea numarului 1, dupa fircare numar par
%model de flux (i, i), (i, o)
add_one_after_even([],[]).
add_one_after_even([H|T], [H, 1|Result]) :-
	0 is H mod 2,
	!,
	add_one_after_even(T, Result).

add_one_after_even([H|T], [H|Result]) :-
	add_one_after_even(T, Result).

final(L):- add_one_after_even(L, R), !,
	write(R).
test_all():-
	assertion(final([1, 2, 3, 4])),
	assertion(final([2, 2, 4, 6])),
	assertion(final([])),
	assertion(final([1, 3, 5, 7])).
