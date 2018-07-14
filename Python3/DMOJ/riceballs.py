import sys
import time

# 0-1 Knapsack now
# values = [100, 20, 60, 40]
# weights = [3, 2, 4, 1]
# w_limit = 5
# n = len(weights)
# dp = [[0 for x in range(w_limit+1)] for y in range(n+1)]
# for i in range(1, n+1):
#     for j in range(1, w_limit+1):
#         if weights[i-1] <= j:
#             dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1])
#         else:
#             dp[i][j] = dp[i-1][j]
# print(dp, end="\n\n")
# for row in dp:
#     print(row)
#     # print(row, end='\n')
# print("Result:", dp[n][w_limit])

sys.stdin = open("input.txt", 'r')

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

# global sizes, dp

# def solved(l, r):
#   if l == r:
#       return True
#   else:
#       return dp[l][r] != -1

# def rangeSum(l, r):
#   if l == r:
#       return sizes[l]
#   else:
#       return dp[l][r]

# def duos(l, r):
#   for i in range(l+1, r+1):
#       j = i - 1
#       if not solved(l, j) or not solved(i, r):
#           continue
#       lsum = rangeSum(l, j)
#       rsum = rangeSum(i, r)
#       if lsum != rsum:
#           continue
#       dp[l][r] = lsum + rsum
#       return True
#   return False

# def trios(l, r):
#   for i in range(l+1, r):
#       j = i - 1
#       if not solved(l, j):
#           continue
#       lsum = rangeSum(l, j)
#       for k in range(i+1, r+1):
#           m = k - 1
#           if not solved(i, m) or not solved(k, r):
#               continue
#           rsum = rangeSum(k, r)
#           if lsum != rsum:
#               continue
#           csum = rangeSum(i, m)
#           dp[l][r] = lsum + rsum + csum

# ans = 0
# N = int(input())
# dp = [[-1 for a in range(N)] for b in range(N)]
# sizes = [int(a) for a in input().split()]
# for i in range(2, N+1):
#   for l in range(N-i+1):
#       r = l + i - 1
#       if duos(l, r):
#           continue
#       if i > 2:
#           trios(l, r)

# for i in range(N):
#   for j in range(i, N):
#       ans = max(ans, rangeSum(i, j))
# print(ans)

global sizes, dp, sums

def getR(i, j):
    if i == j:
        return sizes[i]
    return sums[j] - sums[i-1]

def combine(i, j):
    if dp[i][j] == -1:
        res = 0
        if i >= j:
            res = 1
        else:
            a = i
            b = j
            while a < b:
                c = getR(i, a)
                d = getR(b, j)
                if c < d:
                    a += 1
                elif d < c:
                    b -= 1
                else:
                    res = max(res, combine(i, a) * combine(a+1, b-1) * combine(b, j))
                    a += 1
                    b -= 1
        dp[i][j] = res
    return dp[i][j]

def search(l, r):
    if dp[l][r] == -1:
        val = 0
        if l >= r:
            val = 1
        else:
            i = l
            j = r
            while i < j:
                lsum = getR(l, i)
                rsum = getR(j, r)
                if lsum < rsum:
                    i += 1
                elif rsum < lsum:
                    j -= 1
                else:
                    if search(l, i) == 1 and search(i+1, j-1) == 1 and search(j, r) == 1:
                        val = 1
                        break
                    i += 1
                    j -= 1
        dp[l][r] = val
    return dp[l][r]

n = int(input())
inp = input().split()
dp = [[-1 for x in range(n+1)] for y in range(n+1)]
sums = [0] * (n+1)
sizes = [0] * (n+1)
ans = 0

for i in range(1, n+1):
    sizes[i] = int(inp[i-1])
    sums[i] = sums[i-1] + sizes[i]

# print(sizes)
# print(sums)

t1 = time.time()
for i in range(n+1):
    for j in range(i, n+1):
        # ans = max(ans, combine(i, j) * getR(i, j))
        if search(i, j) == 1:
            ans = max(ans, getR(i, j))
t2 = time.time()
print(ans)
print(t2 - t1)

dp = [[-1 for x in range(n+1)] for y in range(n+1)]
t1 = time.time()
for i in range(n+1):
    for j in range(i, n+1):
        ans = max(ans, combine(i, j) * getR(i, j))
t2 = time.time()
print(ans)
print(t2 - t1)