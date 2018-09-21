package Main;

import java.io.PrintWriter;
import java.util.ArrayList;
import static java.lang.Math.max;

public class dmpg18s4 {
    static ArrayList<Integer>[] adj;
    static int[] dp;
    static int[] arr;
    static boolean[] parity;
    static int N;

    static void printv(int ...a) {
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

    static void printlnv(int ...a) {
        printv(a);
        System.out.println();
    }

    static int DFS(int d, int e, int prev) {
        int ans = d;
        for (int v : adj[e]) {
            if (e != prev) {
                if (parity[e] != parity[v]) {
                    ans = max(ans, DFS(d + 1, v, e));
                }
            }
        }
        System.out.println("d = " + d);
        return ans;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        N = in.nextInt();
        adj = new ArrayList[N];
        arr = new int[N];
        dp = new int[N];
        parity = new boolean[N];
        for (int i = 0; i < N; ++i) {
            adj[i] = new ArrayList<>();
            dp[i] = -1;
            arr[i] = in.nextInt();
            parity[i] = arr[i] % 2 == 0;
        }
        for (int i = 0; i < N - 1; ++i) {
            adj[in.nextInt() - 1].add(in.nextInt() - 1);
        }
        int ans = DFS(0,  arr[0], -1);
        System.out.println(ans);
    }
}
