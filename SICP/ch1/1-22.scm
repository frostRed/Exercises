(define (prime? n)
  (= n (smallest-divisor n) ))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divide? n test-divisor) test-divisor)
        (else (find-divisor n
                            (+ test-divisor 1)))))

(define (divide? a b)
  (= 0 (remainder a b)))

(define (square a) (* a a))
  
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

(define (search-for-primes n count)
  (cond ((= count 0)
         (newline))
        ((prime? n)
         (timed-prime-test n)
         (search-for-primes (next-odd n)
                            (- count 1)))
        (else (search-for-primes (next-odd n)
                                 count))))

(define (next-odd n)
  (if (odd? n)
    (+ n 2)
    (+ n 1)))
