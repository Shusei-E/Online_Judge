; SCIP Chapter 1, 1.1

; 1.1.1
486

(+ 137 349)
(- 1000 334)
(* 5 99)
(/ 10 2.0)

(+ (* 3 5) (- 10 6))

; 1.1.2
(defvar size 2)
(defvar pi 3.14159)
(defvar radius 10)

(* pi (* radius radius))

(defvar circumference (* 2 pi radius))
circumference

; 1.1.3
(* (+ 2 (* 4 6))
   (+ 3 5 7)
   )

; 1.1.4
(defun square(x) (* x x))

(square 21)
(square (+ 2 5))
(square (square 3))

(defun sum-of-squares (x y) 
    (+ (square x) (square y))
)
(sum-of-squares 3 4)

; 1.1.5
(defun f(a)
  (sum-of-squares (+ a 1) (* a 2))
  )

(f 5)

; 1.1.6
(defun data-type (x)
  (cond
    ((integerp x) (print "整数です"))
    ((floatp x)   (print "浮動小数点数です"))
    ((listp x)    (print "リストです"))
    ((symbolp x)  (print "シンボルです"))
    ((stringp x)  (print "文字列です"))
    (t (print "その他のデータです"))))
