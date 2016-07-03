(define (square x) (* x x))

(define (expmod b n m)
  (cond ((= n 0) 1)
        ((even? n)
         (remainder (square (expmod b (/ n 2) m))
                    m))
        (else (remainder (* b (expmod b (- n 1) m))
                         m))))

(define (prime? n)
  (try 1 n))


(define (try a n)
  (cond ((= a n) (display "prime") true)
        ((not (= a (expmod a n n))) (display a) false)
        (else (try (+ a 1) n))))
