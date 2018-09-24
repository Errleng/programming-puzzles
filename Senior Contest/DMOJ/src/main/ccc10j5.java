package main;

import main.FastReader;
import sun.awt.image.ImageWatched;

import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;

public class ccc10j5 {

    static boolean inBounds(int r, int c) {
        return (r >= 1 && c >= 1 && r <= 8 && c <= 8);
    }

    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int[] move_x = {1, 2, 2, 1, -1, -2, -2, -1};
        int[] move_y = {2, 1, -1, -2, -2, -1, 1, 2};

        int s_r = in.nextInt();
        int s_c = in.nextInt();
        int e_r = in.nextInt();
        int e_c = in.nextInt();

        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(s_r, s_c, 0));

        while (!q.isEmpty()) {
            Pos p = q.poll();
            if (p.r == e_r && p.c == e_c) {
                out.println(p.d);
                break;
            }
            for (int i = 0; i < 8; ++i) {
                int n_r = p.r + move_x[i];
                int n_c = p.c + move_y[i];
                if (inBounds(n_r, n_c)) {
                    q.add(new Pos(n_r, n_c, p.d + 1));
                }
            }
        }
    }
}

class Pos {
    int r, c, d;
    Pos(int a, int b, int z) {
        r = a;
        c = b;
        d = z;
    }
}
