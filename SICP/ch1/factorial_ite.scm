(define (factorial n)

    (define (fac-iter prod counter max-counter)
        (if (> counter max-counter)
            prod
            (fac-iter (* prod counter) (+ counter 1) max-counter)))
  (fac-iter 1 1 n))

