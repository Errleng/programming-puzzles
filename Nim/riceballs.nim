import strutils, sequtils, times, os

discard stdin.reopen("input.txt")

proc Run() =
    const MAX = 400

    var n : int = parseInt(readline(stdin))
    var inp = readline(stdin).split

    var ans : int = 0
    var dp : array[0..MAX, array[0..MAX, int]]
    var balls : array[0..MAX, int]
    var sums : array[0..MAX, int]

    for i in 1..n:
        balls[i] = inp[i-1].parseInt
        sums[i] = sums[i-1] + balls[i]

    proc getR(i, j: int) : int =
        # if i == j:
        #     return balls[i]
        return sums[j] - sums[i-1]

    proc search(l, r: int) : int =
        if dp[l][r] == 0:
            var val = -1
            if l >= r:
                val = 1
            else:
                var i = l
                var j = r
                while i < j:
                    var lsum = getR(l, i)
                    var rsum = getR(j, r)
                    if lsum < rsum:
                        inc(i)
                    elif rsum < lsum:
                        dec(j)
                    else:
                        if search(l, i) == 1 and search(i+1, j-1) == 1 and search(j, r) == 1:
                            val = 1
                            break
                        inc(i)
                        dec(j)
            dp[l][r] = val
        return dp[l][r]
    
    for i in 1..n:
        for j in i..n:
            if search(i, j) == 1:
                ans = max(ans, getR(i, j))

    # for i in 0..<dp.len:
    #     var n = newSeq[int]()
    #     for j in 0..<dp[i].len:
    #         if dp[i][j] == 1:
    #             n.add(getR(i,j))
    #         else:
    #             n.add(dp[i][j])
    #     echo n

    echo ans


let startTime = cpuTime()

Run()

let endTime = cpuTime()
echo "Duration: ", endTime - startTime