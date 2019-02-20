#lang racket

(define (min-index lst)
  (define (min-index-recur list i m)
    (cond [(empty? list) m]
          [(< (car list) (list-ref lst m)) (min-index-recur (rest list) (+ i 1) i)]
          [else (min-index-recur (rest list) (+ i 1) m)]))
  (min-index-recur lst 0 0))

(define (solve i j A B)
  (define (solve-rec a b)
    (cond [(or (< a 0) (< b 0)) 0]
          [else (min (+ (solve-rec (- a 1) (- b 1)) (list-ref A a)) (+ (solve-rec (- a 1) (- b 2)) (list-ref B a)))]))
  (solve-rec i j)
  )

(define N 6)
(define A '(8 6 6 6 6 6))
(define B '(4 8 8 4 8 8))

(define N2 5)
(define A2 '(2 2 2 2 2))
(define B2 '(1 1 1 1 1))

(println (solve (- N 1) (- N 1) A B))
(println (solve (- N2 1) (- N2 1) A2 B2))