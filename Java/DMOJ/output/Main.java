import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
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
        dmopc14c4p6 solver = new dmopc14c4p6();
        solver.solve(1, in, out);
        out.close();
    }

    static class dmopc14c4p6 {
        static ArrayList<Integer>[] adj;
        static int[] distFi;
        static int[] distSe;
        static int maxD;
        static int maxI;

        static void dfs(int u, int p, int d, int type) {
            if (d > maxD) {
                maxD = d;
                maxI = u;
            }
            if (type == 1) {
                distFi[u] = d;
            } else if (type == 2) {
                distSe[u] = d;
            }
            for (int e : adj[u]) {
                if (e != p) {
                    dfs(e, u, d + 1, type);
                }
            }
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int N = in.nextInt();
            adj = new ArrayList[N];
            distFi = new int[N];
            distSe = new int[N];
            for (int i = 0; i < N; ++i) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < N - 1; ++i) {
                int a = in.nextInt();
                int b = in.nextInt();
                --a;
                --b;
                adj[a].add(b);
                adj[b].add(a);
            }
            dfs(0, -1, 1, 0);
            int fi = maxI;
            maxD = 0;
            dfs(fi, -1, 1, 1);
            int se = maxI;
            maxD = 0;
            dfs(se, -1, 1, 2);
            System.out.println(Arrays.toString(distFi) + " " + Arrays.toString(distSe));
            for (int i = 0; i < N; ++i) {
                out.println(Math.max(distFi[i], distSe[i]));
            }
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

