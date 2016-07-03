(define (half-interval-method f a b)
  (let ((a-value (f a))
        (b-value (f b)))
    (cond ((and (positive? a-value)
                (negative? b-value))
           (search f b a))
          ((and (negative? a-value)
                (positive? b-value))
           (search f a b))
          (else (error "error arguments")))))

(define (search f neg pos)
  (let ((mid ((lambda (a b) (/ (+ a b) 2.0)) neg pos)))
    (if (close-enough? neg pos)
      mid
      (let ((fmid (f mid)))
        (cond ((positive? fmid)
               (search f neg mid))
              ((negative? fmid)
               (search f mid pos))
              (else mid))))))


(define (close-enough? x y) (< (abs (- x y)) 0.001))
