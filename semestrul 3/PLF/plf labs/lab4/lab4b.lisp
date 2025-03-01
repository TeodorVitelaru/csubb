(defun invers (lst)
  (if (null lst)
      nil
      (append (invers (cdr lst)) (list (car lst)))))

(defun succesor (lst carry)
  (cond
    ((and (null lst) (= carry 1)) (list 1))

    ((null lst) nil)

    ((and (= (car lst) 9) (= carry 1))
     (cons 0 (succesor (cdr lst) 1)))

    ((and (/= (car lst) 9) (= carry 1))
     (cons (+ (car lst) 1) (succesor (cdr lst) 0)))

    (t (cons (car lst) (succesor (cdr lst) 0)))))

(defun main (lst)
 ( invers (succesor (invers lst) 1)))
