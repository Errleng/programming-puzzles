import sys
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

a, b, c, d, Q = tuple(map(int, input().split()))
X = []
for i in range(Q):
    X.append(int(input()))

comp = {}

def f(x, a, b, c, d):
    if x in comp:
        return comp[x]
    if x <= 0:
        return 1
    else:
        comp[x] = f(x//a - b, a, b, c, d) + f(x//c - d, a, b, c, d)
        # print(f(int(x/float(a) - b), a, b, c, d), f(int(x/float(c) - d), a, b, c, d))
    return comp[x]

for x in range(100):
    print(f(x, a, b, c, d), x//a, x//c, x//a * (-b), x//c * (-d))
