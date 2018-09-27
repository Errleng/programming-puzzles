package main;

import java.util.*

class ccc12s4 {
    fun rebase(base: Int, exp: Int): Int {
        var res = 1
        for (i in 1..exp) {
            res *= base
        }
        return res
    }

    fun toID(coins: Array<Stack<Int>>): String {
        var res = ""
        var first = true
        for (i in 0 until coins.size) {
            if (first) {
                if (coins[i].isEmpty()) {
                    res += "0"
                } else {
                    for (elem in coins[i]) {
                        res += elem.toString()
                    }
                }
                first = false
            } else {
                res += "/"
                if (coins[i].isEmpty()) {
                    res += "0"
                } else {
                    for (elem in coins[i]) {
                        res += elem.toString()
                    }
                }
            }
        }
        return res
    }

    fun top(s: Stack<Int>): Int {
        if (s.isEmpty()) {
            return Int.MAX_VALUE
        } else {
            return s.peek()
        }
    }

    fun topPoll(s: Stack<Int>): Int {
        if (s.isEmpty()) {
            return Int.MAX_VALUE
        } else {
            return s.pop()
        }
    }

    fun solve(inp: FastScanner) {
        var N = inp.nextInt()
        do {
            var ans = -1
            var targetID = 0
            var start = State(0)
            for (i in 1..N) {
                var a = inp.nextInt()
                start.coins[i].push(a)
                targetID += a
            }
            start.id = toID(start.coins)

            var q = LinkedList<State>()
            q.push(start)
            var vis = HashSet<String>()
            while (q.isNotEmpty() && ans == -1) {
                var cur = q.poll()
                var possible = true
                for (i in 0 until N) {
                    if (top(cur.coins[i]) >= top(cur.coins[i + 1])) {
                        possible = false
                        break
                    }
                }
                var count = 0
                for (i in 1..N + 1) {
                    if (top(cur.coins[i]) > top(cur.coins[i - 1])) {
                        count++
                    }
                    if (count == N) {
                        ans = cur.dist
                        break
                    }
                }
                if (ans != -1) {
                    break
                }
                if (vis.contains(cur.id))
                    continue
                else
                    vis.add(cur.id)
                for (i in 1..N) {
                    if (i > 1 && top(cur.coins[i]) < top(cur.coins[i - 1])) {
                        var next = State(cur.dist + 1)
                        for (j in 0 until cur.coins.size) {
                            next.coins[j] = cur.coins[j].clone() as Stack<Int>
                        }
                        var a = topPoll(next.coins[i])
                        if (a != Int.MAX_VALUE) {
                            next.coins[i - 1].push(a)
                            next.id = toID(next.coins)
                            q.push(next)
                        }
                    }
                    if (i < N && top(cur.coins[i]) < top(cur.coins[i + 1])) {
                        var next = State(cur.dist + 1)
                        for (j in 0 until cur.coins.size) {
                            next.coins[j] = cur.coins[j].clone() as Stack<Int>
                        }
                        var a = topPoll(next.coins[i])
                        if (a != Int.MAX_VALUE) {
                            next.coins[i + 1].push(a)
                            next.id = toID(next.coins)
                            q.push(next)
                        }
                    }
                }
            }
            if (ans > 0) {
                println(ans)
            } else {
                println("IMPOSSIBLE")
            }
            N = inp.nextInt()
        } while (N != 0)
    }

    class State {
        var id: String
        var dist: Int
        var coins: Array<Stack<Int>>

        constructor(a: Int) {
            id = ""
            dist = a
            coins = Array<Stack<Int>>(9) { Stack<Int>() }
        }
//        fun set(a: Int, b: Int) {
//            coins[a] = coins[a] or (1 shl b)
//        }
    }
}

