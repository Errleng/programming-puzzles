package main;

import main.FastReader;
import java.io.PrintWriter;

import static java.lang.Math.sqrt;

public class bf3 {

    static boolean isPrime(int n) {
        if (n < 2 ) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int num = in.nextInt();
        while (!isPrime(num)) {
            ++num;
        }
        out.println(num);
    }
}
