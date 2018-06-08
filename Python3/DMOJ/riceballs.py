import sys

# 0-1 Knapsack now
values = [100, 20, 60, 40]
weights = [3, 2, 4, 1]
w_limit = 5
n = len(weights)
dp = [[0 for x in range(w_limit+1)] for y in range(n+1)]
for i in range(1, n+1):
    for j in range(1, w_limit+1):
        if weights[i-1] <= j:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1])
        else:
            dp[i][j] = dp[i-1][j]
print(dp, end="\n\n")
for row in dp:
    print(row)
    # print(row, end='\n')
print("Result:", dp[n][w_limit])
