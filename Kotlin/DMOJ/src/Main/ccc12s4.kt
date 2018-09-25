package Main

import Main.FastScanner
import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.PrintWriter
import java.util.*

class ccc12s4 {
    fun solve(testNumber: Int, inp: FastScanner, out: PrintWriter) {
        do {
            val N = inp.nextInt()
            var start = State()
            var q = LinkedList<State>()
            for (i in 0 until N) {
                start.setBit(i, inp.nextInt())
            }
            q.push(start)
            var impossible = false
            while (!q.isEmpty()) {
                var cur_state = q.poll()
            }
        } while (N != 0)
    }
}

class State {
    var stacks = IntArray(9)
    var count = 0

    constructor() {
    }
    fun getBit(i: Int, j: Int) : Boolean {
        return stacks[i] and (1 shl j) != 0
    }

    fun setBit(i: Int, j: Int) {
        stacks[i] = stacks[i] or (1 shl j)
    }

    fun unsetBit(i: Int, j: Int) {
        stacks[i] = stacks[i] and (1 shl j).inv()
    }

    fun toggleBit(i: Int, j: Int) {
        stacks[i] = stacks[i] xor (1 shl j)
    }
}
