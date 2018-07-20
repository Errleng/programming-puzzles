import sys
file = open("input.txt", "r")
sys.stdin = file
def printMat(mat):
    for i in range(len(mat)):
        line = []
        for j in range(len(mat[i])):
            if mat[i][j] == True:
                line.append(0)
            elif mat[i][j] == False:
                line.append(1)
            elif mat[i][j] == sys.maxsize:
                line.append('I')
            else:
                line.append(mat[i][j])
        print(line)
    print()
N, M = [int(x) for x in input().split()]
maze = []
cams = []
steps = [[sys.maxsize for x in range(M)] for y in range(N)]
conv = ['L', 'R', 'D', 'U']
movex = [0, 0, 1, -1]
movey = [-1, 1, 0, 0]
valid = [[True for x in range(M)] for y in range(N)]
sX, sY = -1, -1
for i in range(N):
    maze.append([])
    line = input()
    for j in range(len(line)):
        maze[i].append(line[j])
        if line[j] == 'S':
            sX, sY = i, j
        elif line[j] == 'C':
            cams.append((i, j))
def validPos(a, b):
    return a > 0 and b > 0 and a < N and b < M
for cam in cams:
    cam_x, cam_y = cam[0], cam[1]
    for i in range(cam_x, N):
        if maze[i][cam_y] == 'W':
            break
        valid[i][cam_y] = False
    for i in range(cam_x, -1, -1):
        if maze[i][cam_y] == 'W':
            break
        valid[i][cam_y] = False
    for i in range(cam_y, M):
        if maze[cam_x][i] == 'W':
            break
        valid[cam_x][i] = False
    for i in range(cam_y, -1, -1):
        if maze[cam_x][i] == 'W':
            break
        valid[cam_x][i] = False
queue = [(sX, sY)]
steps[sX][sY] = 0
if valid[sX][sY]:
    while queue:
        (cx, cy) = queue.pop(0)
        p = maze[cx][cy]
        if p in conv:
            p_ind = conv.index(p)
            nx = cx + movex[p_ind]
            ny = cy + movey[p_ind]
            np = maze[nx][ny]
            if steps[nx][ny] > steps[cx][cy] and np != 'W':
                if valid[nx][ny] or np in conv:
                    steps[nx][ny] = steps[cx][cy]
                    queue.append((nx, ny))
        else:
            for i in range(4):
                nx = cx + movex[i]
                ny = cy + movey[i]
                np = maze[nx][ny]
                if np != 'W' and steps[nx][ny] > steps[cx][cy] + 1:
                    if valid[nx][ny] or np in conv:
                        steps[nx][ny] = steps[cx][cy] + 1
                        queue.append((nx, ny))
for i in range(N):
    for j in range(M):
        if maze[i][j] == '.':
            if steps[i][j] == sys.maxsize:
                print(-1)
            else:
                print(steps[i][j])
