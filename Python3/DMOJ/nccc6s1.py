import sys
input = sys.stdin.readline

N = int(input())
a = [0 for i in range(N)]
for i in range(N):
    a[i] = int(input())
print(sum(a)/float(N))
