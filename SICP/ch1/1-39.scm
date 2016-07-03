(define (cont-frac-ite n d k)
  (define (iter count result )
    (if (= count 0)
      result
      (iter (- count 1)
            (/ (n count)
               (- (d count)
                  result))
            )))
  (iter k 0))

(define (tan-cf x k)
    (cont-frac-ite (lambda (i) (if (= i 1)
                                  x
                                  (* x x)))
                   (lambda (i) (- (* 2 i) 1))
                   k))
