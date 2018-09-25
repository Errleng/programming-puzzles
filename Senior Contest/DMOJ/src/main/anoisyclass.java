package main;

import main.FastReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class anoisyclass {
    static int N;
    static int M;
    static int count;
    static HashSet<Integer>[] adj;
    static boolean peaceAndQuiet;
    static boolean[] vis;
    static boolean[] quieted;

    static void quiet(int node) {
        vis[node] = true;
        for (Integer i : adj[node]) {
            if (vis[i] && !quieted[i]) {
                peaceAndQuiet = false;
                return;
            }
            if (!vis[i]) {
                quiet(i);
            }
        }
        quieted[node] = true;
    }

    public void solve(int testNumber, FastReader in, PrintWriter out) {
        N = in.nextInt();
        M = in.nextInt();
        adj = new HashSet[N];
        vis = new boolean[N];
        quieted = new boolean[N];
        peaceAndQuiet = true;
        for (int i = 0; i < N; ++i) {
            adj[i] = new HashSet<>();
        }
        for (int i = 0; i < M; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            adj[a].add(b);
        }
        for (int i = 0; i < N; ++i) {
            quiet(i);
            if (!peaceAndQuiet) {
                break;
            }
        }
        if (peaceAndQuiet) {
            out.println("Y");
        } else {
            out.println("N");
        }
    }
}
