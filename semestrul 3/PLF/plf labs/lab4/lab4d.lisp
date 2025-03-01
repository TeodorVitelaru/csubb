(defun multime (lst)
  (multime_aux lst nil))

(defun multime_aux (lst aux)
  (cond
    
    ((null lst) t) 
  
    ((member_x (car lst) aux) nil)
  
    (t (multime_aux (cdr lst) (cons (car lst) aux)))))

(defun member_x (elem lst)
  (cond
   
    ((null lst) nil)
    
    ((equal elem (car lst)) t)
    
    (t (member_x elem (cdr lst)))))

