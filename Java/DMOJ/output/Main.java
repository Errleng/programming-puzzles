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
        ccc15s3 solver = new ccc15s3();
        solver.solve(1, in, out);
        out.close();
    }

    static class ccc15s3 {
        int find(int[] arr, int x) {
            while (x != arr[x]) {
                arr[x] = arr[arr[x]];
                x = arr[x];
            }
            return x;
        }

        void unite(int[] arr, int x, int y) {
            int top_x = find(arr, x);
            int top_y = find(arr, y);
            arr[top_x] = top_y;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int G = in.nextInt();
            int P = in.nextInt();
            int[] d = new int[G + 1];
            for (int i = 0; i < G + 1; ++i) {
                d[i] = i;
            }
            for (int i = 0; i < P; ++i) {
                int g = in.nextInt();
                int top = find(d, g);
                if (top == 0) {
                    out.println(i);
                    return;
                }
                unite(d, top, top - 1);
            }
            out.println(P);
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

