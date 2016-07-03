(define (square x) (* x x))

(define (expmod b n m)
  (cond ((= n 0) 1)
        ((test? b m)
         0)
        ((even? n)
         (remainder (square (expmod b (/ n 2) m))
                    m))
        (else (remainder (* b (expmod b (- n 1) m))
                         m))))

(define (test? a b)
  (and (not (= a 1))
       (not (= a (- b 1)))
       (= 1 (remainder (square a) b))))

(define (miller-test n)
  (define (try-it a)
    (= 1 (expmod a (- n 1) n)))
  (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
  (cond ((= times 0) true)
        ((miller-test n) (fast-prime? n (- times 1)))
        (else false)))

(define (prime? n)
  (fast-prime? n (n2half n)))

(define (n2half n)
  (if (even? n)
    (/ n 2)
    (/ (- n 1) 2)))
