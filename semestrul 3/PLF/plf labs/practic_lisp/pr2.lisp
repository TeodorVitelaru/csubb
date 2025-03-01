(defun subliste (l)
(cond
	((null l) nil)
	((listp (car l))
		(append (list (car l))
			(subliste (car l))
			(subliste (cdr l))))
	(t (subliste (cdr l)))
)
)

(defun main (l)
(append (list l) (subliste l)))


(defun inloc (l)
(cond
	((and (null (cdr l)) (atom (car l))) (car l))
	((atom (car l)) (inloc (cdr l)))
	(t (inloc (car l)))
)
)

(defun functie (l)
(cond
	((null l) nil)
	((listp (car l)) (cons (inloc (car l)) (functie (cdr l))))
	(t (cons (car l) (functie (cdr l))))
)
)




(defun numara (l nr)
(cond
	((null l) nr)
	((atom (car l)) (numara (cdr l) (+ nr 1)))
	(t (+ (numara (car l) nr) (numara (cdr l) nr)))

)
)

(defun primul (l)
(cond
	((null l) nil)
	((atom (car l)) (car l))
	(t (primul (car l)))

)
)

(defun verifica (l)
(cond
	((null l) nil)
	((and (listp (car l)) (oddp (numara (car l) 0))) 
		(cons (primul (car l)) (verifica (cdr l))) )
	(t (verifica (cdr l)))

)
)



