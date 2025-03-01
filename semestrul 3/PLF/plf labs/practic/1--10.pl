cmmdc(A, 0, A):-!.
cmmdc(0, B, B):-!.

cmmdc(A, B, Rez):-
    R is A mod B,
    cmmdc(B, R, Rez).

final([E],E):-!.

final([A,B|T], Rez):-
    cmmdc(A,B, Rezultat),
    final([Rezultat|T], Rez).
