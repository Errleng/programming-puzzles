# COOL STUFF WITH FIBONACCI SEQUENCE
import math
import times

proc is_prime(n: int) : bool =
    for i in countup(2, n, 2):
        if n mod i == 0:
            return false

proc gcd(a, b: int) : int =
    if a == 0 or b == 0:
        return 0
    if a == b:
        return a
    if a > b:
        return gcd(a-b, b)
    return gcd(a, b-a)

proc lcm(a, b: int) : int =
    return (a * b) div gcd(a, b)

proc fib(n: int64) : int64 =
    var a, b, temp : int64
    if n == 0:
        return 0 
    a = 0
    b = 1
    for i in 1..<n:
        temp = b
        b = a + b
        a = temp
    return b

proc sieve_seq(n: int64) : seq[int64] =
    var primes = newSeq[int64]()
    var not_prime = newSeq[bool](n+1)
    var p : int64
    p = 2
    while p * p <= n:
        if not not_prime[p.int]:
            for i in countup((p*2).int, (n).int, p.int):
                not_prime[i] = true
        p += 1
    for i in 2..<n:
        if not not_prime[i.int]:
            primes.add(i)
    return primes

proc prime_factorize(n: int64) : seq[(int, int)] =
    var prime_factors = newSeq[(int, int)]()
    var is_prime = newSeq[int](n+1)
    var a = n
    while a mod 2 == 0:
        a = a div 2
        is_prime[2] += 1
    for i in countup(3, sqrt(n.float).int, 2):
        while a mod i == 0:
            is_prime[i] += 1
            a = a div i
    for i in 0..<is_prime.len:
        if is_prime[i] > 0:
            prime_factors.add((i, is_prime[i]))
    if prime_factors.len == 0:
        prime_factors.add((n.int, 1))
    return prime_factors

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

proc pisano_period_matrix(m: int64) : int64 =
    var v = newSeq[int64]()
    v.add(1)
    v.add(1)
    var t : int64
    while true:
        t = (v[v.len-1] + v[v.len-2]) mod m
        v.add(t)
        if t == 0 and v.len mod 2 == 0 and v[0..(v.len div 2)-1] == v[(v.len div 2)..(v.len-1)]:
            return v.len div 2
    return v.len div 2

proc fib_mod_m(n, m: int64) : int64 =
    var pisano_length : int64
    pisano_length = pisano_period_matrix(m)
    var rem = n mod pisano_length
    return fib(rem) mod m

proc fib_mod_seq(n, m: int64) : seq[int64] =
    var a, b, temp : int64
    var f_seq = fib_seq(n)
    for i in 0..<len(f_seq):
        f_seq[i] = f_seq[i] mod m
    return f_seq

let dmoj_m = 10 ^ 9 + 7
let dmoj_pisano_period = 2000000016
var n = 10^5
var rem = n mod dmoj_pisano_period
var f = 0
var s = 1
var res = rem
for i in 1..<rem:
    res = (f + s) mod dmoj_m
    f = s
    s = res
echo res mod dmoj_m