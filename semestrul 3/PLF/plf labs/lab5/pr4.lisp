(defun copii (l)
  (cond
    ((null l) 0)
    ((null (car l)) (copii (cdr l)))
    (t (+ 1 (copii (cdr l))))))

(defun convert (tree)
  (cond
    ((null tree) nil)
    (t (append
         (list (car tree) (copii (cdr tree)))
	 (convert (cadr tree))
 	 (convert (caddr tree))
       )
     )  
   ) 
) 
