%predecesor(List:List, Rest:Int, List:List)
%List -> lista de prelucrat
%Rest -> flag dupa care se scade
%Rezultat -> lista rezultata
%model de flux: (i,o,o) , (i,i,i)
%model matematic: prdecesor([l1,l2,...ln],f)=
%=[], daca n=0
%=[9], daca n=1, l1=0, setam f=1
%=[l1-1], daca n=1, l1!=0, setam f=0
%=9 + predecesor([l2...ln], f=1), daca n>1, l1=0 si f=1
%=l1-f1 + predecesor([l2...ln], f1), daca n>1, l1!=0 si f=0

predecesor([],_,[]).
%daca ultima cfira este 0, setam restul 1 si punem 9
predecesor([0], 1, [9]).
%daca ultima cifra nu este 0, setam restul 0 si o scadem
predecesor([H], 0, [NewH]):-
    NewH is H-1,!.
%daca restul este 1 si ultima cifra este 0, adaugam 9
predecesor([0|T], 1, [9|Result]):-
    predecesor(T, 1, Result).
%daca restul este 0 si ultima cifra este dif de 0
predecesor([H|T], 0, [NewH|Result]):-
    predecesor(T, NewR, Result),
    !,
    NewH is H-NewR.



%main_functie(List:List, Result:List)
%List -> lista data
%Result -> lista rezultata
%model de flux: (i,i), (i,o)
%model matematic: main_functie([l1,l2...ln])=
%=[], daca n=0
%=predecesor[l1] + main_functie([l2...ln]), daca l1-lista si n>=1
%=l1 + main_functie([l2...ln]), daca l1-numar si n>=1
main_functie([], []).
main_functie([H|T], [Res|Result]):-
    is_list(H),!,
    predecesor(H, 0, Res),
    main_functie(T, Result).
main_functie([H|T], [H|Result]):-
    number(H),
    main_functie(T, Result).


