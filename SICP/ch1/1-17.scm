(define (double x) (* 2 x))
(define (halve x) (/ x 2))
(define (even? x) (= (remainder x 2) 0))

(define (prod-fast a b)
  (cond ((even? b) (prod-fast (double a)
                              (halve b)))
        (else (+ a
                 (prod-fast a
                            (- b 1))))))

