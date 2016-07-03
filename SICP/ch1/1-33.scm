(define (prime? n)
  (= n (smallest-divisor n) ))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divide? n test-divisor) test-divisor )
        (else (find-divisor n
                            (+ test-divisor 1)))))

(define (divide? a b)
  (= 0 (remainder a b)))
(define (square a) (* a a))

(define (gcd a b)
  (if (= b 0)
    a
    (gcd b (remainder a b))))



(define (filtered-accumulate-rec test? combiner null-value term a next b)
  (cond ((> a b) null-value)
       ((not (test? (term a))) (combiner null-value
                                        (filtered-accumulate-rec test? combiner null-value term (next a) next b)))
       (else (combiner (term a)
                      (filtered-accumulate-rec test? combiner null-value term (next a) next b)))))

(define (filtered-accumulate-ite test? combiner null-value term a next b)
  (define (iter a result)
    (cond ((> a b) result)
          ((not (test? (term a))) (iter (next a)
                                        result))
          (else (iter (next a)
                      (combiner result
                                (term a))))))
  (iter a null-value))

(define (identity x) x)
(define (inc x) (+ x 1))

(define (sum-prime a b)
  (filtered-accumulate-rec prime? + 0 identity a inc b))

(define (prod-gcd n)
  (define (gcd? x)
    (= 1
       (gcd n x)))
  (filtered-accumulate-ite gcd? * 1 identity 1 inc n))
