(define (inc x) (+ x 1))
(define (square x) (* x x))

(define (compose f g)
  (lambda (x) (f (g x))))

(define (repeated-ite f n)
  (define (iter result count)
    (if (= count n)
      result
      (iter (compose f result)
            (+ count 1))))
  (iter f 1))

(define (repeated-rec f n)
  (if (= n 1)
    f
    (compose f (repeated-rec f (- n 1)))))

(define test ((repeated-ite square 2) 5))
