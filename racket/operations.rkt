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



(define my-filter (lambda (lst func)
                    (define filter (lambda (l1 l2 f)
                                     (if (null? l1)
                                         (reverse l2)
                                         (if (f (car l1))
                                             (filter (cdr l1)(cons (car l1) l2) f)
                                             (filter (cdr l1) l2 f)))))
                    (filter lst '() func)))




(define my-map (lambda (lst func)
                 (define mapping (lambda (l1 f l2)
                                   (if (null? l1)
                                       (reverse l2)
                                       (mapping (cdr l1) f (cons (f (car l1)) l2)))))
                 (mapping lst func '())))


(define my-cube (lambda (x)
                  (my-pow x 3)))


(define my-square (lambda (x)
                    (my-mult x x)))



(define major-than-five (lambda (x)
                          (> x 5)))



;(my-map (list 1 2 3 4 5 6) my-cube)
;(my-filter (list 1 2 3 4 5 6 7 8 9 10) major-than-five)
;(my-filter (list 3 4 5 6 7 8 9 10 11) my-even-number)