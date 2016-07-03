(define dx 0.0001)
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

(define (smooth f)
  (lambda (x) (/ (+ (f (- x dx))
                    (f x)
                    (f (+ x dx)))
                 3.0)))

(define (smooth-n f n)
  (repeated-ite (smooth f)
                n))
