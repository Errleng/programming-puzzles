proc exponent_binary(n, x: var int) : int =
    if x < 0:
        var z = -x
        return 1 div exponent_binary(n, z)
    var res = 1
    while x > 0:
        if x mod 2 == 1: # Binary exponent (e.g. 8, 4, 1)
            res *= n
        n *= n
        x = x div 2
    return res

proc mult_mat(x, y: seq[int]) : seq[int] =
    var a, b, c, d : int
    if y.len == 2:
        a = x[0]*y[0] + x[1]*y[1]
        b = x[2]*y[0] + x[3]*y[1]
        return @[a, b]
    a = x[0]*y[0] + x[1]*y[2]
    b = x[0]*y[1] + x[1]*y[3]
    c = x[2]*y[0] + x[3]*y[2]
    d = x[2]*y[1] + x[3]*y[3]
    return @[a, b, c, d]

proc pow_mat(n: var seq[int], x: var int) : seq[int] =
    var res : seq[int]
    res = n 
    while x > 0:
        if x mod 2 == 1:
            res = mult_mat(res, n)
        n = mult_mat(n, n)
        x = x div 2
    return res

proc fib_matrix_exp(n: int) : int =
    # Instead of n^x, we have M^x where M is a matrix
    var A = @[1, 1, 1, 0]
    var V = @[1, 0]
    var x = n - 2
    var res = mult_mat(pow_mat(A, x), V)
    echo res
    return res[0]

var x = 2
var y = 3
echo exponent_binary(x, y)
echo fib_matrix_exp(9)