import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        CCC09S4 solver = new CCC09S4();
        solver.solve(1, in, out);
        out.close();
    }

    static class CCC09S4 {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int N = in.nextInt();
            int T = in.nextInt();
            Graph graph = new Graph(N);

            for (int i = 0; i < T; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                int w = in.nextInt();
                graph.addUDEdge(new Edge(u, w), new Edge(v, w));
            }

            int K = in.nextInt();
            int[] ps = new int[K];
            int[] cs = new int[K];
            for (int i = 0; i < K; ++i) {
                cs[i] = in.nextInt() - 1;
                ps[i] = in.nextInt();
            }
            int[] ds = new int[N];
            Arrays.fill(ds, Integer.MAX_VALUE);
            int dest = in.nextInt() - 1;
            boolean[] vis = new boolean[N];
            ds[dest] = 0;
            for (int i = 0; i < N; ++i) {
                int min = Integer.MAX_VALUE;
                int minIdx = -1;
                for (int j = 0; j < N; ++j) {
                    if (!vis[j] && ds[j] < min) {
                        min = ds[j];
                        minIdx = j;
                    }
                }
                if (minIdx == -1) {
                    break;
                }
                vis[minIdx] = true;
                for (Edge e : graph.adj[minIdx]) {
                    ds[e.id] = Math.min(ds[e.id], ds[minIdx] + e.w);
                }
            }
            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < K; ++i) {
                ans = Math.min(ans, ds[cs[i]] + ps[i]);
            }
            out.println(ans);
        }

    }

    static class Edge {
        int id;
        int w;

        Edge(int node, int weight) {
            this.id = node;
            this.w = weight;
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

    static class Graph {
        final int V;
        ArrayList<Edge>[] adj;

        Graph(int N) {
            this.V = N;
            this.adj = new ArrayList[V];
            for (int i = 0; i < V; ++i) {
                adj[i] = new ArrayList<Edge>();
            }
        }

        public void addUDEdge(Edge u, Edge v) {
            adj[u.id].add(v);
            adj[v.id].add(u);
        }

    }
}

