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

(define (sqrt-iter guess x)
  (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x) x)
  )
)

(define (improve guess x)
  (average guess (/ x guess))
  )

(define (average x y) (/ (+ x y) 2))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001)
  )

(define (sqrt x)
  (sqrt-iter 1.0 x)
  )

(sqrt 9)

(if (good-enough? 3 5)
    0
    1
)

(if (good-enough? 3 9.0000000001)
    0
    1
)

; 1.1.8
; Nesting of definition = block structure
(define (sqrt x)
  (define (good-enough? guess x)
    (< (abs (- (square guess) x)) 0.001)
  )
  (define (improve guess x)
    (average guess (/ x guess))
  )
  (define (sqrt-iter guess x)
    (if (good-enough? guess x)
        guess
        (sqrt-iter (improve guess x) x)
    )
  )
  (sqrt-iter 1.0 x)
)
