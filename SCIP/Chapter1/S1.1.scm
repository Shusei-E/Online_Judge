; 1.1.6

(define (abs x)
  (cond ((> x 0) x)
        ((= x 0) 0)
        ((< x 0) (- x))
  )
)

(define (abs2 x)
  (cond ((< x 0) (- x))
        (else x)
        )
  )
(abs2 -1)

(define (absc x)
  (if (< x 0) (- x) x) 
  )
(absc 5)

