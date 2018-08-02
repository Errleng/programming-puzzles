import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Scanner;
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
        CCC05S5 solver = new CCC05S5();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCC05S5 {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            double ans = 0;
            int T = in.nextInt();
            BIT FT = new BIT(T);
            Elem[] scores = new Elem[T];
            for (int i = 0; i < T; i++) {
                scores[i] = new Elem(i, in.nextInt());
            }
            Arrays.sort(scores, (a, b) -> a.val - b.val);
            for (int i = T - 1; i > -1; i--) {
                FT.update(scores[i].idx + 1, 1);
                ans += FT.query(scores[i].idx + 1);
            }
            ans /= T;
            out.printf("%.2f\n", ans - 1e-9);
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

    static class Elem {
        int val;
        int idx;

        Elem(int a, int b) {
            this.idx = a;
            this.val = b;
        }

    }

    static class BIT {
        int[] Arr;

        public BIT(int size) {
            Arr = new int[size];
            for (int i = 1; i <= size; i++) {
                this.update(i, Arr[i - 1]);
            }
        }

        public BIT(int[] inArr) {
            Arr = new int[inArr.length];
            for (int i = 0; i < inArr.length; i++) {
                Arr[i] = inArr[i];
            }
            for (int i = 1; i <= inArr.length; i++) {
                this.update(i, Arr[i - 1]);
            }
        }

        public void update(int i, int add) {
            while (i <= Arr.length) {
                Arr[i - 1] += add;
                i += i & (-i);
            }
        }

        public int query(int i) {
            int sum = 0;
            while (i > 0) {
                sum += Arr[i - 1];
                i -= i & (-i);
            }
            return sum;
        }

    }
}

