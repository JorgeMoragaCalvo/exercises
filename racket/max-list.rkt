#lang racket
(define major (lambda (x y)
                (> x y)))

(define my-max (lambda (lst)
                 (define (max l n)
                   (if (null? l)
                       n
                       (if (major (car l) n)
                           (max (cdr l) (car l))
                           (max (cdr l) n))))
                 (if (null? lst)
                     #f
                     (max (cdr lst) (car lst)))))

(define lista (list 5 3 4 7 2 6 1))