(define (sum term a next b)
  (if (> a b)
    0
    (+ (term a)
       (sum term
            (next a)
            next
            b))))


(define (integral f a b n)

  (define h (/ (- b a) n))

  (define (fac x)
    (cond ((or (= x 0)
               (= x n)) 1)
          ((odd? x) 4)
          (else 2)))

  (define (term x)
    (* (fac x)
       (f (+ a (* x h)))))

  (define (next x) (+ x 1))

    (if (not (even? n))
        (error "n can't be odd")
        (* (/ h 3)
           (sum term (exact->inexact 0) next n))))


(define (cube x) (* x x x))
