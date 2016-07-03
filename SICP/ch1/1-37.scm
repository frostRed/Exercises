(define (cont-frac-rec n d k)
  (define (try x)
    (if (= x k)
      0
      (/ (n x)
         (+ (d x)
            (try (+ x 1))))))
  (try 1))

(define (cont-frac-ite n d k)
  (define (iter count result )
    (if (= count 0)
      result
      (iter (- count 1)
            (/ (n count)
               (+ (d count)
                  result))
            )))
  (iter k 0))

(define (test k)
  (cont-frac-ite (lambda (i) 1.0)
                (lambda (i) 1.0)
                k))
