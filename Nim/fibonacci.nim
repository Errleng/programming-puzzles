# COOL STUFF WITH FIBONACCI SEQUENCE
import math

proc sieve_seq(n: int64) : seq[int64] =
    var primes = newSeq[int64]()
    var not_prime = array(n+1, bool)
    var p : int64
    p = 2
    while p * p <= n:
        if not not_prime[p]:
            for i in countup(p * 2, n+1, p):
                not_prime[p] = true
        p += 1
    for p in 2..n:
        if not not_prime[p]:
            primes.add(p)
    return primes

proc prime_factorize(n: int64) : seq[int64] =
    var prime_factors = newSeq[int64]()
    var primes = sieve_seq(n)


proc fib_seq(n: int64) : seq[int64] =
    var a, b, temp : int64
    var f_seq = newSeq[int64]()
    f_seq.add(0)
    if n != 0:
        a = 0
        b = 1
        for i in 1..<n:
            f_seq.add(b)
            temp = b
            b = a + b
            a = temp
    return f_seq

proc pisano_period(m: int64) : int64 =
    var a, b, temp : int64
    a = 0
    b = 1
    temp = a + b
    for i in 0..<m*m:
        temp = (a + b) mod m
        a = b
        b = temp
        if a == 0 and b == 1:
            return i + 1

proc fib_mod_m(n, m: int64) : int64 =
    var pisano_length : int64
    pisano_length = pisano_period(m)
    return n mod pisano_length

proc fib_mod_seq(n, m: int64) : seq[int64] =
    var a, b, temp : int64
    var f_seq = fib_seq(n)
    for i in 0..<len(f_seq):
        f_seq[i] = f_seq[i] mod m
    return f_seq

# var dmoj_m = 10 ^ 9 + 7
# echo dmoj_m
# echo fib_mod_seq(90, 10)
# echo fib_mod_m(2015, 3)
echo prime_factorize(2015)