import algorithm

proc fib(n: int) : int =
    var dp = newSeq[int](n+1)
    dp[0] = 0
    dp[1] = 1
    for i in 2..n:
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]

echo "Fibonacci 30: ", fib(30)

# State: set of features that identify a unique position in the problem.
# Ex: Knapsack 0-1 has a state with two parameters: index and weight. The DP table is DP[index][weight].
# It can identify a subproblem by the specific index (item) and weight (value of item)

proc ways_to_sum(target: int, nums: openarray[int]) : int =
    var dp = newSeq[int](target+1)
    dp[0] = 1
    for i in 1..target:
        for j in low(nums)..high(nums):
            if nums[j] <= i:
                dp[i] += dp[i-nums[j]]
    return dp[target]

echo "Number of ways to sum 8 with [1, 3, 5]: ", ways_to_sum(8, [1, 3, 5])

proc tiling(n: int) : int =
    # Given a 2*n board and tiles of size 2x1 return number of ways to tile the board
    # Tiles can be placed horizontally or vertically

    if n <= 2:
        return n
    var dp = newSeq[int](n)
    dp[0] = 1
    dp[1] = 2
    for i in 2..<n:
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n-1]

echo "Tiling board of size 4: ", tiling(4)

proc binomial_coeff(n: int, k: int) : int =
    # Given n and k, find the coefficient of x^k in the expansion of (1 + x)^n

    var dp = newSeq[seq[int]]()
    for i in 0..n:
        dp.add(newSeq[int](k+1))
    for i in 0..n:
        dp[i][0] = 1 # Base case returns 1 in recursive solution
    for i in 1..n:
        for j in 1..k:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    return dp[n][k]

echo "Binomial coefficient for n = 5, k = 2: ", binomial_coeff(8, 2)

proc largest_divisible_pairs(elems: var seq[int]) : int =
    # Given an array of distinct elements, find the length of the largest subset
    # Every pair in the subset has the larger element divisible by the smaller

    elems.sort(system.cmp[int], Descending)
    var dp = newSeq[int](elems.len+1)

    dp[0] = 1 # At the very least, the subsequence is of length 1

    for i in 1..<elems.len:
        var max_elem = 0
        for j in countdown(i-1, 0):
            if elems[j] %% elems[i] == 0:
                max_elem = max(max_elem, dp[j])
        dp[i] = max_elem + 1
    echo dp
    return max(dp)

var pairs = @[10, 5, 3, 15, 20]
echo "Largest divisible pairs of [10, 5, 3, 15, 20]: ", largest_divisible_pairs(pairs)
pairs = @[18, 1, 3, 6, 13, 17]
echo "Largest divisible pairs of [18, 1, 3, 6, 13, 17]: ", largest_divisible_pairs(pairs)
