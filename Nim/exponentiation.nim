proc exponent_binary(n, x: var int) : int =
    if x < 0:
        var z = -x
        return 1 div exponent_binary(n, z)
    var res = 1
    while x > 0:
        if x mod 2 == 1: # Binary exponent (e.g. 8, 4, 1)
            res *= n
        echo "n, x: ", n, " ", x
        n *= n
        x = x div 2
    return res


type Matrix[M,N: static[int]] = array[M, array[N, int64]]

proc mult_mat_seq(x, y: seq[int64]) : seq[int64] =
    var a, b, c, d : int64
    if y.len == 2:
        a = x[0]*y[0] + x[1]*y[1]
        b = x[2]*y[0] + x[3]*y[1]
        return @[a, b]
    a = (x[0]*y[0] + x[1]*y[2]) 
    b = (x[0]*y[1] + x[1]*y[3]) 
    c = (x[2]*y[0] + x[3]*y[2]) 
    d = (x[2]*y[1] + x[3]*y[3])
    return @[a, b, c, d]


proc pow_mat_seq(n: var seq[int64], x: var int64) : seq[int64] =
    var res : seq[int64]
    res = n
    while x > 0:
        if x mod 2 == 1:
            res = mult_mat_seq(res, n)
        n = mult_mat_seq(n, n)
        x = x div 2
    return res

proc mult_mat(a: Matrix; b: Matrix) : Matrix =
    var M = a.len
    var N = a[0].len
    var M2 = b.len
    var N2 = b[0].len
    if M != N:
        echo "Invalid matrix dimensions"
    var res = a
    for i in 0..<M:
        for j in 0..<N2:
            res[i][j] = 0
    for i in 0..<M:
        for j in 0..<N2:
            for k in 0..<N:
                res[i][j] += (a[i][k] * b[k][j])
    return res

proc pow_mat(a: var Matrix, x: var int64) : Matrix =
    var res = a
    while x > 0:
        if x mod 2 == 1:
            res = mult_mat(res, a)
        a = mult_mat(a, a)
        x = x div 2
    return res

proc fib_matrix_exp(n: int64) : int64 =
    # Instead of n^x, we have M^x where M is a matrix
    var A : Matrix[2, 2]
    A = [[1.int64, 1.int64], [1.int64, 0.int64]]
    var x : int64
    x = n - 2
    A = pow_mat(A, x)
    return A[0][0]

var x = 2
var y = 5
echo exponent_binary(x, y)
# echo fib_matrix_exp(9)