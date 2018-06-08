
sequence = [5, 3, 4, 8, 6, 7]
dp = [1] * len(sequence)
for i in range(1, len(sequence)):
    for j in range(i):
        if sequence[i] > sequence[j]:
            dp[i] = max(dp[i], dp[j]+1)
            print(dp, i, j)

print(dp)
print(max(dp))
