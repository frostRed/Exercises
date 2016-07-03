(define tole 0.00001)
(define dx 0.00001)
(define (fixed-point f first-guess)
  (define (enough? a b) (< (abs (- a b)) tole))
  (define (try x)
    (let ((next (f x)))
      (if (enough? x next)
        next
        (try next))))
  (try first-guess))

(define (average-damp f)
  (lambda (x) (/ (+ x (f x))
                 2)))

(define (sqrt-ad x)
  (fixed-point (average-damp (lambda (y) (/ x y)))
               1.0))

(define (derive g)
  (lambda (x)
    (/ (- (g (+ x dx))
          (g x))
       dx)))
(define (newton-transform g)
  (lambda (x)
    (- x
       (/ (g x)
          (derive g) x))))

(define (newton-method g guess)
  (fixed-point (newton-transform g) guess))

(define (sqrt-nt x)
  (newton-method (lambda (y) (- (* y y) x))
                 1.0))


