(define (cuberoot x)
  (cuberoot-iter 1.0 x))

(define (cuberoot-iter guess x)
  (if (guess-enough? guess (improve guess x))
     (improve guess x)
     (cuberoot-iter (improve guess x)
                   x)))

(define (guess-enough? old-guess new-guess)
  (< (/ (abs (- old-guess new-guess))
       old-guess)
    0.001))

(define (improve guess x)
  (/ (+ (/ x (square guess))
       (* 2 guess))
    3))

(define (square x)
  (* x x))
