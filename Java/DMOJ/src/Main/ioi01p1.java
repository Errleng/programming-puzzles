package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.Arrays;

class BIT2D {
    int[][] impl;
    BIT2D(int r, int c) {
        impl = new int[r + 1][c + 1];
    }

    void update(int x, int y, int val) {
        while (x < impl.length) {
            int t_y = y;
            while (t_y < impl[x].length) {
                impl[x][t_y] += val;
                t_y += (t_y & -t_y);
            }
            x += (x & -x);
        }
    }

    public int query(int i, int j) {
        int res = 0;
        while (i > 0) {
            int t_j = j;
            while (t_j > 0) {
                res += impl[i][t_j];
                t_j -= (t_j & -t_j);
            }
            i -= (i & -i);
        }
        return res;
    }

    public int square_query(int i1, int j1, int i2, int j2) {
        return query(i2, j2) + query(i1 - 1, j1 - 1) - query(i1 - 1, j2) - query(i2, j1 - 1);
    }
}

public class ioi01p1 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int op;
        BIT2D tree = null;
        do {
            op = in.nextInt();
            if (op == 0) {
                int s = in.nextInt();
                tree = new BIT2D(s, s);
            } else if (op == 1) {
                int x = in.nextInt() + 1;
                int y = in.nextInt() + 1;
                int a = in.nextInt();
                tree.update(x, y, a);
            } else if (op == 2) {
                int l = in.nextInt() + 1;
                int b = in.nextInt() + 1;
                int r = in.nextInt() + 1;
                int t = in.nextInt() + 1;
                int query_res = tree.square_query(l, b, r, t);
                out.println(query_res);
            }
        } while (op != 3);
    }
}
