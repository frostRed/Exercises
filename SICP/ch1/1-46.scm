(define tolo 0.00001)

(define (ite-improve enough? improve)
  (lambda (x)
    (define (try guess)
      (let ((next (improve guess)))
        (if (enough? guess next)
          next
          (try next))))
    (try x)))

(define (enough? a b)
  (< (abs (- a b))
     tolo))

(define (sqrt x)
    (define (improve guess)
        (average guess (/ x guess)))
    (define (average x y)
        (/ (+ x y) 2))
    ((ite-improve enough? improve) 1.0))

(define (fixed-point f first-guess)
  (define (improve guess)
    (f guess))
  ((ite-improve enough? improve) first-guess))

(define (test)
  (fixed-point cos 1.0))
