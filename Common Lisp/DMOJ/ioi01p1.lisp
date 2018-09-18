(defclass BIT ()
  (size
   :accessor size)
  (arr
   :accessor arr))

(defmethod update ((tree BIT))
  (loop while (<= i size)
        do
        (let ((ref (aref arr (- i 1))))
          (setf ref (+ ref add))
          (setf i (logand i (- i)))
          )))

(defmethod initialize-instance :after ((tree BIT) &key)
  (loop for i from 1 to size
        do
        (update i (aref arr (- i 1)))))
