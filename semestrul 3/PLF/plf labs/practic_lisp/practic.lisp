(defun apare (l e)
(cond
	((null l) 0)
	((and (numberp (car l)) (eq (car l) e)) (+ 1 (apare (cdr l) e)))
	((listp (car l)) (+ (apare (car l) e) (apare (cdr l) e)))
	(t (apare (cdr l) e))
))

(defun inloc (l aux)
(cond
	((null l) nil)
	((and (atom (car l)) (< (apare aux (car l)) 2)) 
				(cons (car l) (inloc (cdr l) aux)))
	((listp (car l)) (cons (inloc (car l) aux) (inloc (cdr l) aux)))
	(t (cons (+ 1 (car l)) (inloc (cdr l) aux)))

))

(defun main (l)
(inloc l l))
