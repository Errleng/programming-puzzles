package Main;

import java.io.PrintWriter;
import java.util.ArrayList;

public class dmpg18s4 {
    static ArrayList<Integer>[] adj;
    static int[] arr;
    static int[] rep;
    static int[] len;
    static boolean[] par;
    static int N;
    static int ans;
    static int cur;

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
