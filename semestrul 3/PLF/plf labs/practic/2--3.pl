insereaza(X, [], [X]).
insereaza(X, [H|T], [X,H|T]):-
    X<H,!.
insereaza(X, [H|T], [H|T]):-
    X = H,!.
insereaza(X, [H|T], [H|R]):-
    insereaza(X, T, R).

main([], []).
main([H|T], R):-
    main(T, Rez),
    insereaza(H, Rez, R).
