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
