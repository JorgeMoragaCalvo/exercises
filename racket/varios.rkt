#lang racket
(define fac (lambda (x)
              (if (= x 1)
                  x
                  (* x (fac (- x 1))))))



(define square (lambda (x)
                 (* x x)))

(define lista (list 2 3 4 5 6))

#|Determinar largo de una lista|#
(define my-length (lambda (lst)
                     (define size (lambda (l n)
                                    (if (null? l)
                                        n
                                        (size (cdr l) (+ n 1)))))
                     (size lst 0)))


#|Invertir una lista|#
(define my-reverse (lambda (lst)
                     (define wrapped-reverse (lambda (l1 l2)
                                            (if (= 1 (my-length l1))
                                                (cons (car l1) l2)
                                                (wrapped-reverse (cdr l1) (cons (car l1) l2)))))
                     (wrapped-reverse lst '())))


#|Elevar todos los elementos de una lista (de numeros) al cuadrado|#
(define square-map (lambda (lst)
                     (define square-mapping (lambda (l1 l2)
                                              (if (= 1 (my-length l1))
                                                  (cons (square (car l1)) l2)
                                                  (square-mapping (cdr l1)(cons (square (car l1)) l2)))))
                     (my-reverse (square-mapping lst '()))))


#|Largo de una cadena de texto|#
(define my-string-length (lambda (str)
                           (define count-char (lambda (s count)
                                                (if (string=? s "") ;string=? -> compara la cadena si s == " "
                                                    count
                                                    (count-char (substring s 1) (+ count 1)))))
                           (count-char str 0)))

#|Filtrar palabras segun el largo|#
(define my-word-filter (lambda (lst num)
                         (define word-filter (lambda (l1 n l2)
                                               (if (null? l1)
                                                   (my-reverse l2)
                                                   (if (> (my-string-length (car l1)) n)
                                                       (word-filter (cdr l1) n (cons (car l1) l2))
                                                       (word-filter (cdr l1) n l2)))))
                         (word-filter lst num '())))



(define sum-list (lambda (lst)
                   (define wrapped-sum-list (lambda (l acc)
                                              (if (null? l)
                                                  acc
                                                  (wrapped-sum-list (cdr l)(+ (car l) acc)))))
                   (wrapped-sum-list lst 0)))


(define sum-square-list (lambda (lst)
                               (sum-list (square-map lst))))

(define words (list "spray" "limit" "elite" "exuberant" "destruction" "present"))

#|
(define my-word-filter
  (lambda (lst num)
    (define word-filter
      (lambda (l1 n acc)
        (cond
          ((null? l1) (reverse acc))
          ((> (my-string-length (car l1)) n)
           (word-filter (cdr l1) n (cons (car l1) acc)))
          (else (word-filter (cdr l1) n acc)))))
    (word-filter lst num '())))
|#

;(my-word-filter words 5)

;(my-string-length word)


;(square-map lista)

(define decimal-to-binary (lambda (num)
                            (define binary (lambda (n l)
                                             (if (< n 2)
                                                 (cons n l)
                                                 (binary (quotient n 2) (cons (remainder n 2) l)))))
                            (binary num '())))

(define decimal-to-octal (lambda (num)
                           (define octal (lambda (n l)
                                           (if (< n 8)
                                               (cons n l)
                                               (octal (quotient n 8) (cons (remainder n 8) l)))))
                           (octal num '())))


(define hexa (lambda (num)
               (cond
                 [(< num 10) num]
                 [(= num 10) "A"]
                 [(= num 11) "B"]
                 [(= num 12) "C"]
                 [(= num 13) "D"]
                 [(= num 14) "E"]
                 [(= num 15) "F"])))

(define decimal-to-hexa (lambda (num)
                          (define wrapped-hexa (lambda (n l)
                                                (if (< n 16)
                                                    (cons (hexa n) l)
                                                    (wrapped-hexa (quotient n 16) (cons (hexa (remainder n 16)) l)))))
                          (wrapped-hexa num '())))

(define triple (lambda (num)
                 (* num 3)))

(define triple-map (lambda (lst)
                     (define wrapped-triple-map (lambda (l1 l2)
                                                  (if (= (my-length l1) 1)
                                                      (cons (triple(car l1)) l2)
                                                      (wrapped-triple-map (cdr l1) (cons (triple (car l1)) l2)))))
                     (my-reverse (wrapped-triple-map lst '()))))