import sys

sys.stdin = open("input.txt")
input = sys.stdin.readline

N = int(input())
print(N)
A = list(map(int, input().split()))
total = sum(A)
dp = [[0 for i in range(total + 1)] for j in range(2)]

for i in range(total + 1):
    dp[0][i] = abs(i - (total - i))

for i in range(N):
    for j in range(total + 1):
        if j - A[i] >= 0:
            dp[1][j] = min(dp[0][j], dp[0][j-A[i]])
        else:
            dp[1][j] = 1e9
    dp[0] = list(dp[1])
print(dp[1][total])
