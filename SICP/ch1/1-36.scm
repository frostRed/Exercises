(define tole 0.00001)
(define (fixed-point f first-guess)
  (define (enough? a b) (< (abs (- a b)) tole))
  (define (try x)
    (display x)
    (newline)
    (let ((next (f x)))
      (if (enough? x next)
        next
        (try next))))
  (try first-guess))

(define (f n)
  (fixed-point (lambda (x) (/ (log n) (log x))) 2.0))
(define (f- n)
  (fixed-point (lambda (x) (/ (+ x (/ (log n) (log x)))
                             2.0)) 2.0))