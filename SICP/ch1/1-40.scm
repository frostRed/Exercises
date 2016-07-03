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

(define (derive g)
  (lambda (x)
    (/ (- (g (+ x dx))
          (g x))
       dx)))
(define (newton-transform g)
  (lambda (x)
    (- x
       (/ (g x) ((derive g) x)))))

(define (newton-method g guess)
  (fixed-point (newton-transform g) guess))

(define (cubic a b c)
  (lambda (x) (+ (* x x x)
                 (* a x x)
                 (* b x)
                 c)))
