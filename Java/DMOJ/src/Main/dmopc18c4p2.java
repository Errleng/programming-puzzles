package Main;

import Main.FastScanner;
import java.io.PrintWriter;

public class dmopc18c4p2 {
    static final int MAX = 700 * 700;
    static int total;
    static int[][] dp;
    static int[] A;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int N = in.nextInt();
        total = 0;
        A = new int[N];
        for (int i = 0; i < N; ++i) {
            A[i] = in.nextInt();
            total += A[i];
        }
        dp = new int[2][total + 1];
        for (int i = 0; i <= total; ++i) {
            dp[0][i] = Math.abs(i - (total - i));
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= total; ++j) {
                if (j - A[i] >= 0) {
                    dp[1][j] = Math.min(dp[0][j], dp[0][j-A[i]]);
                } else {
                    dp[1][j] = Integer.MAX_VALUE;
                }
            }
            System.arraycopy(dp[1], 0, dp[0], 0, dp[1].length);
        }
        out.println(dp[1][total]);
    }
}
