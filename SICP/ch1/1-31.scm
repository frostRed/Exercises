(define (product_rec term a next b)
  (if (> a b)
    1
    (* (term a)
       (product_rec term (next a) next b))))

(define (product_ite term a next b)
  (define (iter a result)
    (if (> a b)
      result
      (iter (next a) (* result
                        (term a)))))
  (iter a 1))

(define (pi-prod a b)
  (define (term x)
    (* (/ (- x 1) x)
       (/ (+ x 1) x)))
  
  (define (next x)(+ x 2))

  (if (< a 3)
     (error "must >= 3")
     (product_ite term a next b)))
