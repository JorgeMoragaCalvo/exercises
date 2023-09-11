#lang racket
(define my-index-of (lambda (lst num)
                    (define index-of (lambda (l n accu)
                                      (if (null? l)
                                          #f
                                          (if (= (car l) n)
                                                 accu
                                                 (index-of (cdr l) n (+ accu 1))))))
                    (index-of lst num 0)))

(define my-list (list 5 3 4 7 2 6 1))

(my-index-of my-list 2)