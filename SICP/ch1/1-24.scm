(define (square x) (* x x))

(define (expmod b n m)
  (cond ((= n 0) 1)
        ((even? n)
         (remainder (square (expmod b (/ n 2) m))
                    m))
        (else (remainder (* b (expmod b (- n 1) m))
                         m))))

(define (fermat-test n)
  (define (try-it a)
    (= a (expmod a n n)))
  (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
  (cond ((= times 0) true)
        ((fermat-test n) (fast-prime? n (- times 1)))
        (else false)))


(define (prime? n)
  (fast-prime? n 1))
  
(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (runtime)))

(define (start-prime-test n start-time)
  (if (prime? n)
    (report-prime (- (runtime) start-time))))

(define (report-prime elapsed-time)
  (display " *** ")
  (display elapsed-time))
