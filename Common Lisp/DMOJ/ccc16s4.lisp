(defun printer (&rest args)
    (format t "~{~a~^ ~}" args))
(defun split-string (string delimiter)
  (loop :for s = (position-if-not delimiter string)
        :then (position-if-not delimiter string :start (+ 1 e))
        :for e = (and s (position-if delimiter string :start s))
        :when s :collect (subseq string s e)
        :while e))
(defun read-array ()
  (let* ((line (read-line))
         (elems (split-string line (lambda (c) (char= c #\Space))))
         (nums (map 'vector 'parse-integer elems)))
    nums))
(let* ((N (read))
      (arr (read-array))
      (memo (make-array (list (+ N 1) (+ N 1)) :initial-element -1))
      (sum-table (make-array (+ N 1)))
      (ans -1))
  (defun range-sum (a b)
    (cond ((= a b)
           (aref arr (- a 1)))
          (t
           (- (aref sum-table b) (aref sum-table (- a 1))))))
  (setf (aref sum-table 0) 0)
  (loop for i from 1 to N
        do
           (setf (aref sum-table i) (+ (aref sum-table (- i 1)) (aref arr (- i 1)))))
  ; (print sum-table)
  (defun combine (l r)
      (cond
        ((/= (aref memo l r) -1)
         ; (printer "memo" l r (aref memo l r) #\linefeed)
         (aref memo l r))
        ((>= l r)
         (setf (aref memo l r) 1))
        (t
         ; (printer #\linefeed "Looping" l r #\linefeed)
         (let ((s l)
               (e r))
           (loop while (< l r)
                 do
                    ; (printer l r (range-sum s l) (range-sum r e) #\linefeed)
                    (let ((ls (range-sum s l))
                          (rs (range-sum r e)))
                      (cond ((< ls rs) (incf l))
                            ((> ls rs) (decf r))
                            (t
                             ; (printer s l r e (combine s l) (combine (+ l 1) (- r 1)) (combine r e) #\linefeed)
                             (if (and (= (combine s l) 1) (= (combine (+ l 1) (- r 1)) 1) (= (combine r e) 1))
                                 (progn
                                   (return-from combine (setf (aref memo s e) 1))
                                   ))
                             (incf l)
                             (decf r)
                             ))
                      )
                 )
           (setf (aref memo s e) 0)
           )
         )
      ))
  (loop for i from 1 to N
        do
           (loop for j from i to N
                 do
                    (if (= (combine i j) 1)
                        (progn
                          ; (printer #\linefeed "can combine" i j (range-sum i j) #\linefeed)
                          (setq ans (max ans (range-sum i j)))
                          )
                        )
                 )
        )
  (print ans)
  )
