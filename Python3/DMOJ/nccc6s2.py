import sys
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

N = int(input())
grid = [[] for i in range(N)]
for i in range(N):
    grid[i] = list(map(int, input().split()))
K = 0
cor = [[0 for i in range(N)] for j in range(N)]
for i in range(N):
    if K == 0:
        for j in range(N):
            num = i*N + j + 1
            if grid[i][j] != num:
                K += 1
print(K)
