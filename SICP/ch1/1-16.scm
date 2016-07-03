(define (expt-fast b n)
  (expt-fast-iter b n 1))

(define (expt-fast-iter b n a)
  (cond ((= n 0) a)
        ((even? n) (expt-fast-iter (square b)
                                   (/ n 2)
                                   a))
        (else (expt-fast-iter b
                              (- n 1)
                              (* a b)))))

(define (square x) (* x x))
