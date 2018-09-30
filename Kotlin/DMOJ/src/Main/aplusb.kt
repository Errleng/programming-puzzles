package main

class aplusb {
    fun solve(inp: FastScanner) {
        val N = inp.nextInt()
        for (i in 0 until N) {
            val a = inp.nextInt()
            val b = inp.nextInt()
            println(a + b)
        }
    }
}