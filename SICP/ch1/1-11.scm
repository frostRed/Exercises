(define (f-rec n)
  (if (< n 3)
    n
    (+
      (f-rec (- n 1))
      (* 2
         (f-rec (- n 2)))
      (* 3
         (f-rec (- n 3))))))

(define (f-iter n)
  (iter 0 1 2 n))

(define (iter a b c counter)
  (cond ((= counter 0) a)
        ((= counter 1) b)
        ((= counter 2) c)
        (else
          (iter b
                c
                (+ c
                   (* 2 b)
                   (* 3 a))
                (- counter 1)))))
