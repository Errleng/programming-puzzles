import sys
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

X, Y, N = tuple(map(int, input().split()))
s_x, s_y = tuple(map(int, input().split()))
e_x, e_y = tuple(map(int, input().split()))
wind = [[False for i in range(N)] for j in range(N)]
vis = [[False for i in range(N)] for j in range(N)]
for i in range(N):
    x, y = tuple(map(int, input().split()))
    wind[x][y] = True

q = [(s_x, s_y, 0, 0)]
while q:
    (c_x, c_y, v_x, v_y) = q.pop(0)
    vis[c_x][c_y] = True
