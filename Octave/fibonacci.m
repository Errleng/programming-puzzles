function f = fibonacci (n)
  A = [1, 1; 1, 0]
  V = [1; 0]
  f = A^(n-1) * V
endfunction