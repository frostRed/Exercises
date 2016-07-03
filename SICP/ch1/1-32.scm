(define (accumulate-rec combiner null-value term a next b)
  (if (> a b)
    null-value
    (combiner (term a)
              (accumulate-rec combiner null-value term (next a) next b))))

(define (accumulate-ite combiner null-value term a next b)
  (define (iter x result)
    (if (> x b)
      result
      (iter (next x)
            (combiner result
                      (term x)))))
  (iter a null-value))

(define (sum-rec term a next b)
  (accumulate-rec + 0 term a next b))
(define (sum-ite term a next b)
  (accumulate-ite + 0 term a next b))

(define (prod-rec term a next b)
  (accumulate-rec * 1 term a next b))
(define (prod-ite term a next b)
  (accumulate-ite * 1 term a next b))



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