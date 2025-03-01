(defun remove_n (lst n)
  (cond
    ;; Cazul 1: Lista este goală sau poziția n este invalidă
    ((or (null lst) (<= n 0)) lst)

    ;; Cazul 2: Suntem pe poziția n, eliminăm primul element
    ((= n 1) (cdr lst))

    (t (cons (car lst) (remove_n (cdr lst) (- n 1)))))
    )