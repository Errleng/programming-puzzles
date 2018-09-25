package main;

import main.FastReader;
import java.io.PrintWriter;

public class ccc96s3 {

    static void pattern(PrintWriter out, String s, int a, int b) {
        boolean ones = b > 0;
        if (a > 0) {
            if (ones) {
                pattern(out, s + "1", a - 1, b - 1);
            }
            pattern(out, s + "0", a - 1, b);
        } else if (!ones) {
            out.println(s);
        }
    }

    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        for (int i = 0; i < N; ++i) {
            out.println("The bit patterns are");
            int n = in.nextInt();
            int k = in.nextInt();
            pattern(out, "", n, k);
            out.println();
        }
    }
}
