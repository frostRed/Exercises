(define (sum term a next b)
  (if (> a b)
    0
    (+ (term a)
       (sum term (next a) next b))))

(define (identity x) x)
(define (cube x) (* x x x))
(define (pi-sum-term x)
  (/ 1.0 (* x (+ x 2))))

(define (inc x) (+ x 1))
(define (pi-sum-next x) (+ x 4))

(define (sum-integers a b)
  (sum identity a inc b))

(define (sum-cubes a b)
  (sum cube a inc b))

(define (pi-sum a b)
  (sum pi-sum-term a pi-sum-next b))

(define (integral f a b dx)
  (define (add-dx x) (+ x dx))
  (* (sum f
       (+ a (/ dx 2))
       add-dx
       b)
    dx))

