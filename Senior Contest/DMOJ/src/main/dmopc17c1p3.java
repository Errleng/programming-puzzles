package main;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class dmopc17c1p3 {

    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        int M = in.nextInt();
        int[] dist = new int[N];
        int[] realDist = new int[N];
        Arrays.fill(dist, Integer.MAX_VALUE);
        ArrayList<Edge>[] adj = new ArrayList[N];
        for (int i = 0; i < N; ++i) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int t = in.nextInt();
            adj[a].add(new Edge(b, t, 0));
            adj[b].add(new Edge(a, t, 0));
        }
        PriorityQueue<Edge> q = new PriorityQueue<>();
        dist[0] = 0;
        q.add(new Edge(0, 0, 0));
        while (!q.isEmpty()) {
            Edge u = q.poll();
            System.out.println(u.w);
            if (u.w > dist[u.id]) {
                continue;
            }
            for (Edge e : adj[u.id]) {
                int nd = dist[u.id] + e.w;
                if (nd < dist[e.id] || (nd == dist[e.id] && realDist[u.id] + 1 < realDist[e.id])) {
                    dist[e.id] = nd;
                    realDist[e.id] = realDist[u.id] + 1;
                    q.add(new Edge(e.id, nd, realDist[e.id]));
                }
            }
        }
        if (dist[N - 1] == Integer.MAX_VALUE) {
            out.println(-1);
        } else {
            out.println(dist[N - 1] + " " + realDist[N - 1]);
        }
    }

    class Edge implements Comparable<Edge> {
        int id;
        int w;
        int dist;

        Edge(int a, int b, int c) {
            id = a;
            w = b;
            dist = c;
        }

        public int compareTo(Edge o) {
            if (w == o.w) {
                return Integer.compare(dist, o.dist);
            } else {
                return Integer.compare(w, o.w);
            }
        }
    }
}

