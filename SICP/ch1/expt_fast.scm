(define (expt-fast b n)
  (cond ((= n 0) 1)
        ((even? n) (square 
                     (expt-fast b (/ n 2))))
        (else (* b (expt-fast b (- n 1))))))

(define (square x) (* x x))

(define (even? n) (= (remainder n 2) 
                    0))
