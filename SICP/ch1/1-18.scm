(define (double x) (* 2 x))
(define (halve x) (/ x 2))
(define (even? x) (= (remainder x 2) 0))

(define (prod-fast-iter a b)
  (iter a b 0))

(define (iter a b c)
  (cond ((= b 1) (+ a c))
        ((even? b) (iter (double a)
                           (halve b)
                           c))
        (else (iter a
                      (- b 1)
                      (+ a c)))))
