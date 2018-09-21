import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        dmpg18s4 solver = new dmpg18s4();
        solver.solve(1, in, out);
        out.close();
    }

    static class dmpg18s4 {
        static ArrayList<Integer>[] adj;
        static int[] dp;
        static int[] arr;
        static boolean[] parity;
        static int N;

        static int DFS(int d, int e, int prev) {
            int ans = d;
            for (int v : adj[e]) {
                if (e != prev) {
                    if (parity[e] != parity[v]) {
                        ans = Math.max(ans, DFS(d + 1, v, e));
                    }
                }
            }
            System.out.println("d = " + d);
            return ans;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            N = in.nextInt();
            adj = new ArrayList[N];
            arr = new int[N];
            dp = new int[N];
            parity = new boolean[N];
            for (int i = 0; i < N; ++i) {
                adj[i] = new ArrayList<>();
                dp[i] = -1;
                arr[i] = in.nextInt();
                parity[i] = arr[i] % 2 == 0;
            }
            for (int i = 0; i < N - 1; ++i) {
                adj[in.nextInt() - 1].add(in.nextInt() - 1);
            }
            int ans = DFS(0, arr[0], -1);
            System.out.println(ans);
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

