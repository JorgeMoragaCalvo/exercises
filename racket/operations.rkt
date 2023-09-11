#lang racket

(define my-mult (lambda (x y)
                  (define mult (lambda (n1 n2 acc)
                                 (if (= n2 0)
                                     acc
                                     (mult n1 (- n2 1)(+ n1 acc)))))
                  (mult x y 0)))

;(my-mult 5 2)


(define hypot (lambda (num1 num2)
                (sqrt (+ (my-mult num1 num1)(my-mult num2 num2)))))



(define my-pow (lambda (x y)
                 (define pow (lambda (n1 n2 acc)
                               (if (= n2 0)
                                   acc
                                   (pow n1 (- n2 1)(my-mult n1 acc)))))
                 (pow x y 1)))



(define my-div (lambda (x y)
                 (define div (lambda (n1 n2 count)
                               (if (or (= n1 0)(< n1 n2))
                                   count
                                   (div (- n1 n2) n2 (+ count 1)))))
                 (div x y 0)))



(define my-remainder (lambda (x y)
                       (if (or (= x 0)(< x y))
                           x
                           (my-remainder (- x y) y))))



(define my-even-number (lambda (x)
                         (if (= (my-remainder x 2) 0)
                             #t
                             #f)))
