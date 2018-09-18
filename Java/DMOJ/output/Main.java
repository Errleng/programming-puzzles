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
        coci07c6p3 solver = new coci07c6p3();
        solver.solve(1, in, out);
        out.close();
    }

    static class coci07c6p3 {
        static int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int N = in.nextInt();
            int[] nums = new int[N];
            int hcf = 0;
            nums[0] = in.nextInt();
            for (int i = 1; i < N; ++i) {
                nums[i] = in.nextInt();
                hcf = gcd(Math.abs(nums[i] - nums[i - 1]), hcf);
            }
            for (int i = 2; i * i <= hcf; ++i) {
                if (hcf % i == 0) {
                    out.print(i + " ");
                    if (i != hcf / i) {
                        out.print((hcf / i) + " ");
                    }
                }
            }
            out.println(hcf);
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

