(define (sum term a next b)
  (define (iter a result)
    (if (> a b)
      result
      (iter (next a) (+ result
                        (term a)))))
  (iter a 0))

(define (pi-sum a b)
  (define (pi-sum-term x)
  (/ 1.0 (* x (+ x 2))))
  (define (pi-sum-next x) (+ x 4))
  (sum-ite pi-sum-term a pi-sum-next b))

(define (pi-prod a b)
  (define (term x)
    (* (/ (- x 1) x)
       (/ (+ x 1) x)))
  (define (next x)(+ x 2))
  (prod-ite term a next b))
