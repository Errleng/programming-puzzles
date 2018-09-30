package main;

import main.FastReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class sssp {

    class Edge implements Comparable<Edge> {
        int id, w;
        Edge(int a, int b) {
            id = a;
            w = b;
        }
        public int compareTo(Edge o) {
            return Integer.compare(w, o.w);
        }
    }

    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        int M = in.nextInt();
        int[] dist = new int[N];
        Arrays.fill(dist, Integer.MAX_VALUE);
        ArrayList<Edge>[] adj = new ArrayList[N];
        for (int i = 0; i < N; ++i) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int c = in.nextInt();
            adj[a].add(new Edge(b, c));
            adj[b].add(new Edge(a, c));
        }
        PriorityQueue<Edge> q = new PriorityQueue<>();
        dist[0] = 0;
        q.add(new Edge(0, 0));
        while (!q.isEmpty()) {
            Edge u = q.poll();
            for (Edge e : adj[u.id]) {
                int nd = dist[u.id] + e.w;
                if (nd < dist[e.id]) {
                    dist[e.id] = nd;
                    q.add(new Edge(e.id, nd));
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            if (dist[i] == Integer.MAX_VALUE) {
                out.println(-1);
            } else {
                out.println(dist[i]);
            }
        }
    }
}

