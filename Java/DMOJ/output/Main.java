import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
        dmpg18s4 solver = new dmpg18s4();
        solver.solve(1, in, out);
        out.close();
    }

    static class dmpg18s4 {
        static ArrayList<Integer>[] adj;
        static int[] arr;
        static int[] rep;
        static int[] len;
        static boolean[] par;
        static int N;
        static int ans;
        static int cur;

        static void printv(int... a) {
            boolean first = true;
            for (int i : a) {
                if (first) {
                    System.out.print(i);
                    first = false;
                } else {
                    System.out.print(" " + i);
                }
            }
        }

        static void printlnv(int... a) {
            printv(a);
            System.out.println();
        }

        static void DFS(int u) {
            rep[u] = cur;
            ++len[cur];
            for (int v : adj[u]) {
                if (rep[v] == -1) {
                    DFS(v);
                }
            }
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            N = in.nextInt();
            adj = new ArrayList[N];
            arr = new int[N];
            rep = new int[N];
            len = new int[N];
            par = new boolean[N];
            ans = 0;
            for (int i = 0; i < N; ++i) {
                adj[i] = new ArrayList<>();
                rep[i] = -1;
                arr[i] = in.nextInt();
                par[i] = arr[i] % 2 == 1;
            }
            for (int i = 0; i < N - 1; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;

                // The alternative
                if (par[a] != par[b]) {
                    printlnv(a, b);
                    adj[a].add(b);
                    adj[b].add(a);
                }
            }
            cur = 0;
            for (int i = 0; i < N; ++i) {
                if (rep[i] == -1) {
                    DFS(i);
                    ++cur;
                }
                if (par[i]) {
                    ans += len[rep[i]];
                }
            }
            out.println(ans);
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

