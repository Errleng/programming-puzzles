package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class dmopc14c4p6 {
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
        for (int e: adj[u]) {
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
        for (int i = 0; i < N; ++i) {
            out.println(Math.max(distFi[i], distSe[i]));
        }
    }
}
