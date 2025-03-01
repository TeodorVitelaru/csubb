%vale(l1..ln)=
%=[], n=0
%=desc(cresc(l1..ln)), daca l1<l2
vale(L):-
    cresc(L, R),
    desc(R),!.



%cresc(l1..ln)=
%=[], daca n=2, l1<l2
%=cresc(l2..ln), daca l1<l2
%=l1..ln, daca l1>=l2
cresc([A,B|[]], []):- A<B.
cresc([A,B|T], [A,B|T]):-
    A>=B.
cresc([A,B|T], R):-
    A<B,
    cresc([B|T], R).

%desc(l1..ln)=
%=true, daca n=2 si l1>l2
%=desc(l2..ln), daca l1>l2 si n>2
%=fals daca l1<=l2
desc([A,B|[]]):-
    A>B.
desc([A,B|T]):-
    A>B,
    desc([B|T]).

%suma(l1..ln, poz)=
%=0, daca n=0
%=l1+suma(l2..ln, poz+1), daca poz%2=1
%=l1-suma(l2..ln, poz+1), daca poz%2=0

suma([],_,0).
suma([H|T], Poz, S):-
    0 is Poz mod 2,
    Poz1 is Poz +1,
    suma(T, Poz1, S1),
    S is S1+H.
suma([H|T], Poz, S):-
    1 is Poz mod 2,
    Poz1 is Poz + 1,
    suma(T, Poz1, S1),
    S is S1-H.


