(defun inlocuieste (ab nv nn)
(cond
	((null ab) nil)
	((equal (car ab) nv)
		(cons nn (mapcar #'(lambda (subarbore)
					(inlocuieste subarbore nv nn))
					(cdr ab))))
	(t (cons (car ab)
		(mapcar #'(lambda (subarbore)
				(inlocuieste subarbore nv nn))
				(cdr ab))))
)

)