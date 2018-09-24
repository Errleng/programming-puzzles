package main;

import main.FastReader;
import java.io.PrintWriter;
import java.util.*;

import static java.lang.Math.min;

public class ccc09s4 {
    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        int T = in.nextInt();
        int[] pencilCost = new int[N];
        Arrays.fill(pencilCost, -1);
        int[] dists = new int[N];
        Arrays.fill(dists, Integer.MAX_VALUE);
        int[][] adj = new int[N][N];

        for (int i = 0; i < T; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            int c = in.nextInt();
            adj[x][y] = c;
            adj[y][x] = c;
        }
        int K = in.nextInt();
        for (int i = 0; i < K; ++i) {
            pencilCost[in.nextInt() - 1] = in.nextInt();
        }

        int D = in.nextInt() - 1;

        dists[D] = 0;
        int min = Integer.MAX_VALUE;
        boolean[] vis = new boolean[N];
        for (int i = 0; i < N; ++i) {
            int m = -1;
            for (int j = 0; j < N; ++j) {
                if (!vis[j] && m== -1 || !vis[j] && dists[j] < dists[m]) {
                    m = j;
                }
            }
            if (dists[m] >= min) {
                break;
            }
            vis[m] = true;
            for (int j = 0; j < adj[m].length; ++j) {
                if (adj[m][j] != 0) {
                    dists[j] = min(dists[j], dists[m] + adj[m][j]);
                }
            }
            if (pencilCost[m] != -1) {
                min = min(min, dists[m] + pencilCost[m]);
            }
        }
        out.println(min);
    }
}
