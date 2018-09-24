package main;

import main.FastReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class vmss7wc16c3p2 {
    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        int M = in.nextInt();
        int A = in.nextInt();
        int B = in.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[N + 1];
        boolean[] vis = new boolean[N + 1];
        for (int i = 0; i <= N; ++i) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; ++i) {
            int a = in.nextInt();
            int b = in.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.add(A);
        boolean go = false;
        while(!queue.isEmpty()) {
            Integer n = queue.poll();
            if (n == B) {
                go = true;
                break;
            }
            vis[n] = true;
            for (Integer i : adj[n]) {
                if (!vis[i]) {
                    queue.add(i);
                }
            }
        }
        if (go) {
            out.println("GO SHAHIR!");
        } else {
            out.println("NO SHAHIR!");
        }
    }
}
