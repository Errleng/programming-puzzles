package main;

import main.FastReader;
import java.io.PrintWriter;

public class dmpg17s2 {
    static int[] disjoint;

    static int find(int x) {
        while (x != disjoint[x]) {
            disjoint[x] = disjoint[disjoint[x]];
            x = disjoint[x];
        }
        return x;
    }

    static void union(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            disjoint[rootx] = rooty;
        }
    }

    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        int Q = in.nextInt();
        disjoint = new int[N];
        for (int i = 0; i < N; ++i) {
            disjoint[i] = i;
        }
        for (int i = 0; i < Q; ++i) {
            String c = in.next();
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            if (c.equals("A")) {
                union(x, y);
            } else {
                out.println((find(x) == find(y) ? "Y" : "N"));
            }
        }
    }
}
