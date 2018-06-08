
N = int(input())
mat = []
for i in range(N):
    mat.append([int(x) for x in input().split()])
copy_mat = [x[:] for x in a]

def rotateLeft(matrix):
    res_matrix = []
    for i in range(len(matrix)):
        for j in range(len(matrix)):


correct = True
while not correct:
    for i in range(N-1):
        if mat[i][0] > mat[i + 1][0]:
            mat = rotateLeft(mat)
        for j in range(N - 1):
            if mat[i][j] > mat[i][j+1]:
                mat = rotateLeft(mat)