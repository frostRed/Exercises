(define (count-charge amount)
  (cc amount 5))

(define (cc amount kinds)
  (cond ((= amount 0) 1)
        ((or (= kinds 0)
             (< amount 0))
         0)
        (else (+
                (cc amount (- kinds 1))
                (cc (- amount (first-denomination kinds)) kinds)))))

(define (first-denomination kinds)
  (cond ((= kinds 1) 1)
        ((= kinds 2) 5)
        ((= kinds 3) 10)
        ((= kinds 4) 25)
        ((= kinds 5) 50)))
