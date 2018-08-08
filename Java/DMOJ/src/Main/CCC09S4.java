package Main;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class CCC09S4 {
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
            int cur = -1;
            for (int j = 0; j < N; ++j) {
                if (!vis[j] && ds[j] < min) {
                    min = ds[j];
                    cur = j;
                }
            }
            if (cur == -1) {
                break;
            }
            vis[cur] = true;
            for (Edge e : graph.adj[cur]) {
                ds[e.id] = Math.min(ds[e.id], ds[cur] + e.w);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < K; ++i) {
            ans = Math.min(ans, ds[cs[i]] + ps[i]);
        }
        out.println(ans);
    }
}

class Graph {
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

class Edge {
    int id, w;

    Edge(int node, int weight) {
        this.id = node;
        this.w = weight;
    }
}
