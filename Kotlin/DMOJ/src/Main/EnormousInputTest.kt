package Main;

import Main.FastScanner;
import java.io.PrintWriter;

class EnormousInputTest {
    fun solve(testNumber: Int, inp: FastScanner, out: PrintWriter) {
        var n = inp.nextInt()
        var k = inp.nextInt()
        var divisible = 0
        for (i in 1..n) {
            var a = inp.nextInt()
            if (a % k == 0)
                divisible++
        }
        out.println(divisible)
    }
}
