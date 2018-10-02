import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int G = in.nextInt();
            int P = in.nextInt();
            ArrayList<Integer> remaining = new ArrayList<>();
            for (int i = 0; i < G; i++) {
                remaining.add(i);
            }
            for (int i = 0; i < P && remaining.size() > 0; i++) {
                int g = in.nextInt() - 1;
                int lo = 0;
                int hi = remaining.size() - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (g < remaining.get(mid)) {
                        hi = mid - 1;
                    } else if (g > remaining.get(mid)) {
                        lo = mid + 1;
                    } else {
                        lo = mid + 1;
                        break;
                    }
                }
                if (lo > 0)
                    lo -= 1;
                if (remaining.get(lo) <= g) {
                    remaining.remove(lo);
                } else {
                    out.println(i);
                    return;
                }
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

