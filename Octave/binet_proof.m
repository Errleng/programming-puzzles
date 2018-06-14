#http://www.math.ucsd.edu/~math18/Fall/Lab4/Lab4.shtml
function res = binet_proof (y)
  A = [8, 11, 2, 8; 
       0, -7, 2, -1; 
       -3, -7, 2, 1; 
       1, 1, 2, 4]
  B = [1, -2, 0, 5;
       0, 7, 1, 5;
       0, 4, 4, 0;
       0, 0, 0, 2]
  C = [1, 1; 1, 0] # Fibonacci Q matrix
  
  [v, e] = eig(C) # v = eigenvectors, e = eigenvalues
  
  detC = det(C) # det = product of e
  detA = det(A)
  detB = det(B)
  
  [P, D] = eig(B) # P = eigenvectors of B as columns. D = diagonal matrix with corresponding eigenvalues along the diagonal
  x = P(:, 2) # x = 2nd eigenvector
  B * x - 8 * x # Bx = 8x because x is 2nd column eigenvalue of B, which is equal to the diagonal matrix D(2,2) = 8
  # Observe: Bx = ax ; B is the matrix (Matrix), x is an eigenvector of B (Vector), a is an eigenvalue of B (Scalar)
  
  v = [9, -4, -2, 0;
       -56, 32, -28, 44;
       -14, -14, 6, -14;
       42, -33, 21, -45]
  [vP, vD] = eig(v)
  inv(vP) * v * vP # Approximately the diagonal matrix vD
  # V is diagonalizable if vP is an invertible matrix and inv(vP) * V * vP is diagonal
  # A diagonal matrix is easily to perform operations with
  # Consider V^100. Express V as vP * vD * inv(vP) or in general notation PDinv(P) or PDP^-1
  # V^100 = (PDinv(P))^100 = (PDinv(P)(PDinv(P))(PDinv(P)...(PDinv(P))
  # = PD(inv(P)P)D(inv(P)P)D(inv(P)P)...Dinv(P)
  # Observe: (inv(P)P) can be factored out
  # = P(D^100)inv(P)
  # D^100 is easily computed. In a diagonal matrix D, D^n is all entries of D to the n
  
  # Theorem: If an nxn matrix has n distinct eigenvalues, it is diagonalizable
  # Conversely, the eigenvalues of a diagonalizable matrix are not necessarily distinct
  # Ex: The identity matrix is diagonalizable (it's already diagonal)
  
  # Fibonacci with PDinv(P)
  # f = (f0, f1)'
  # Apostrophe (') is the transpose operator in Octave
  f = [0, 1]'
  
  # Ff = (f1, f0 + f1)' = (f1, f2)'
  # (F^2)f = F(Ff) = F * (f1, f2)' = (f2, f1 + f2)' = (f2, f3)
  # (F^n)f = (fn, f(n+1))'
  
  F = [1, 1; 1, 0]
  [FP, FD] = eig(F)
  inv(FP) * F * FP
  (FP * FD^9 * inv(FP)) * f # F = FP * FD * inv(FP) or PDinv(P)

  # Derive explicit formula
  # We see the eigenvalues of F are -0.61803 and 1.61803
  # Notice that 1.61803 is the golden ratio; (1 + sqrt(5))/2
  # Notice that -0.61803 is (1 - sqrt(5))/2
  # Let a = (1 + sqrt(5))/2
  # Let e = (1 - sqrt(5))/2
  a = (1 + sqrt(5))/2
  e = (1 - sqrt(5))/2
  # F^n = FP(FD^n)inv(FP) =
  # [a, e; 1 1] * [a^n, 0; 0, e^n] * inv([a, e; 1, 1])
  FP * FD * inv(FP)
  P = [a, e; 1, 1]
  D = [a, 0; 0, e]
  X = P * D * inv(P)
  (FP * FD * inv(FP)) - (P * D * inv(P)) # Practically equal
  # X = (1 / sqrt(5)) * 
  #[a^(n+1) - e^(n+1) - (a^(n+1) * e) + (e^(n+1) * a);
  # a^n - e^n - (a^n * e) + (e^n * a)]
  n = 7
  XRes = [a^(n+1) - e^(n+1) - (a^(n+1) * e) + (e^(n+1) * a);
          a^n - e^n - (a^n * e) + (e^n * a)]
  # F^n = (1 / sqrt(5)) * XRes
  (1 / sqrt(5)) * XRes
endfunction
