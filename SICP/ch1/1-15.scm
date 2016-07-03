(define (cube x) (* x x x))
(define (p x)
  (- (* 3 x)
     (* 4 (cube x))))

(define (sine angles)
  (if (not (> angles 0.1))
    angles
    (p (sine 
         (/ angles 3)))))
