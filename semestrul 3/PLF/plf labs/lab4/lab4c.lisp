(defun atoms (lst aux)
  (cond
    ;; Dacă lista este goală, returnăm o listă goală
    ((null lst) nil)
    
    ((and (atom (car lst)) (nu_apare (car lst) aux)) 
          (cons (car lst) (atoms (cdr lst) (cons (car lst) aux))))

    ((atom (car lst)) (atoms (cdr lst) aux))
    
    (t (atoms (append (car lst) (cdr lst)) aux))))



(defun nu_apare (elem lst)
  (cond
  
    ((null lst) t)
   
    ((equal elem (car lst)) nil)
  
    (t (nu_apare elem (cdr lst)))))


(defun main (lst)
  (atoms lst nil))





