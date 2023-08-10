#lang racket

(define lista (list 1 2 3 4))

#|Suma de numeros de una lista|#
(define sum (lambda (lst)
              (define sum-b (lambda (l num)
                              (if (null? l)
                                  num
                                  (sum-b (cdr l) (+ (car l) num)))))
              (sum-b lst 0)))
#|********************************************************************|#

#| Funcion para determinar si un numero es par|#
(define even? (lambda (num)
                (= (remainder num 2) 0)))
#|********************************************************************|#

#| Funcion para determinar la cantidad de numeros pares en una lista|#
(define evens (lambda (lst)
                (define evens-b (lambda (l cont)
                                  (if (null? l)
                                      cont
                                      (evens-b (cdr l) (+ (if(even? (car l)) 1 0) cont)))))
                (evens-b lst 0)))
#|********************************************************************|#

(sum lista)
(evens lista)