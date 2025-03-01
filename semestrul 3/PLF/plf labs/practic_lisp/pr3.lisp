
(defun nivel (ab niv nod)
(cond
	((null ab) nil)
	((eq (car ab) nod) niv)
	(t (or (nivel (cadr ab) (+ niv 1) nod) 
		(nivel (caddr ab) (+ niv 1) nod)))
)
)

(defun preordine (ab)
(cond
	((null ab) nil)
	(t (cons (car ab) 
		(append (preordine (cadr ab))
			(preordine (caddr ab)))))

)
)



(defun apare (ab x)
(cond
	((null ab) nil)
	((eq (car ab) x) T)
	(t (or (apare (cadr ab) x)
		(apare (caddr ab) x)))

)
)

(defun calea (ab x)
(cond
	((null ab) nil)
	((eq (car ab) x) (list x))
	((apare (cadr ab) x) (cons (car ab) (calea (cadr ab) x)))
	((apare (caddr ab) x) (cons (car ab) (calea (caddr ab) x)))
	(t nil)

))




(defun adancime (ab)
(cond
	((null ab) 0)
	((and (null (cadr ab)) (null (caddr ab))) 1)
	(t (+ 1 (max (adancime (cadr ab)) 
			(adancime (caddr ab)))))

))

(defun echilibrat (ab)
(cond
	((null ab) T)
	( nil)
	((and (<= (- (adancime (cadr ab)) (adancime (caddr ab))) 1)
		 (>= (- (adancime (cadr ab)) (adancime (caddr ab))) -1)) nil)
	(t (and (echilibrat (cadr ab)) (echilibrat caddr ab)))

))





