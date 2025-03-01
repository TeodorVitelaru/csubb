(defun inserare (a l pas)
(cond
	((null l) nil)
	((evenp pas) 
		(cons (car l) 
		(cons a (inserare a (cdr l) (+ pas 1)))))
	(t (cons (car l) (inserare a (cdr l) (+ pas 1))))
)
)

(defun functie (l)
(cond
	((null l) nil)
	((atom (car l)) (append (functie (cdr l)) (list (car l))))
	(t (append (functie (cdr l)) (functie (car l))))
)
)

(defun div (a b)
(cond
	((= b 0) a)
	(t (div b (mod a b)))
)
)

(defun functie2 (l d)
(cond
	((null l) d)
	(t (functie2 (cdr l) (div (car l) d)))
)
)

(defun main (l)
(functie2 (cdr l) (div (car l) (car l))))




