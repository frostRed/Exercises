(define (compose f g)
  (lambda (x) (f (g x))))

(define (repeated-rec f n)
  (cond ((= 1 n) f)
        ((> n 1) (compose f (repeated-rec f (- n 1))))))

(define (repeated-ite f n)
  (define (iter result count)
    (if (= n count)
      result
      (iter (compose f result) (+ count 1))))
  (iter f 1))

(define (ave-damp f)
  (lambda (x) (/ (+ x
                    (f x))
                 2.0)))

(define tole 0.00001)
(define (fixed-point f first-guess)
  (define (enough? a b) (< (abs (- a b)) tole))
  (define (try x)
    (let ((next (f x)))
      (if (enough? x next)
        next
        (try next))))
  (try first-guess))

(define (fixed-point-of-transform f transform guess)
  (fixed-point (transform f) guess))

(define (expt-fast b n)
  (cond ((= n 0) 1)
        ((even? n) (square 
                     (expt-fast b (/ n 2))))
        (else (* b (expt-fast b (- n 1))))))

(define (square x) (* x x))

(define (nth-root x n)
  (define (search a)
    (define (iter-s left right)
      (let ((less (expt-fast 2 left))
            (much (expt-fast 2 right)))
      
        (if (or (and (> a  less)
                     (= a  less))
                (< a much))
           left
           (iter-s right (+ right 1)))))
    (iter-s 1 2))
  (fixed-point-of-transform (lambda (y) (/ x (expt-fast y (- n 1))))
                            (repeated-ite ave-damp (search n))
                            1.0))
(define N 32)
(define (test) (nth-root (expt-fast 2 N) N))

