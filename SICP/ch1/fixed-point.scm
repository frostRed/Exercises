(define tole 0.00001)
(define (fixed-point f first-guess)
  (define (enough? a b) (< (abs (- a b)) tole))
  (define (try x)
    (let ((next (f x)))
      (if (enough? x next)
        next
        (try next))))
  (try first-guess))
