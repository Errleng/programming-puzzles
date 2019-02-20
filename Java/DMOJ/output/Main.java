import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        dmopc18c4p2 solver = new dmopc18c4p2();
        solver.solve(1, in, out);
        out.close();
    }

    static class dmopc18c4p2 {
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
                        dp[1][j] = Math.min(dp[0][j], dp[0][j - A[i]]);
                    } else {
                        dp[1][j] = Integer.MAX_VALUE;
                    }
                }
                System.arraycopy(dp[1], 0, dp[0], 0, dp[1].length);
            }
            out.println(dp[1][total]);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream IS) {
            br = new BufferedReader(new
                    InputStreamReader(IS));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

