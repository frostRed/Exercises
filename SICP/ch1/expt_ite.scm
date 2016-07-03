(define (expt b n)
  (expt-iter b n 1))

(define (expt-iter b counter prod)
  (if (= counter 0)
    prod
    (expt-iter b
               (- counter 1)
               (* prod b))))
