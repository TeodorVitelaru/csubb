(defun calea (ab e)
  (cond
    ((null ab) nil)
    ((eq (car ab) e) (list e))
    ((and (listp ab) (apare ab e)) (cons (car ab) 
					(mapcan #'(lambda (subtree) (calea subtree e)) (cdr ab))))  
    (t (mapcan #'(lambda (subtree) 
                  (calea subtree e)) 
              (cdr ab)))))

(defun apare (l e)
(cond
	((null l) nil)
	((eq (car l) e) T)
	((listp (car l)) (or (apare (car l) e) (apare (cdr l) e)))
	(t (apare (cdr l) e))
))