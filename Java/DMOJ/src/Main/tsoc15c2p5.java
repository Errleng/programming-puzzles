package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.Arrays;

public class tsoc15c2p5 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int S = in.nextInt();
        int N = in.nextInt();
        Bebilith.CONVICT_SPEED = S;
        Bebilith[] liths = new Bebilith[N];
        for (int i = 0; i < N; ++i) {
            int B = in.nextInt();
            int D = in.nextInt();
            int C = in.nextInt();
            liths[i] = new Bebilith(i + 1, B, D, C);
        }
        Arrays.sort(liths);
        int Q = in.nextInt();
        for (int i = 0; i < Q; ++i) {
            int q = in.nextInt();
            out.println(liths[q - 1].id);
        }
    }
}

class Bebilith implements Comparable<Bebilith> {
    static int CONVICT_SPEED;
    int id;
    int speed;
    int venom;
    int claw;
    Bebilith(int a, int b, int c, int d) {
        id = a;
        speed = b;
        venom = c;
        claw = d;
    }
    @Override
    public int compareTo(Bebilith o) {
        if (speed != o.speed) {
            return o.speed - speed;
        } else if (speed >= CONVICT_SPEED) {
            if (o.claw == claw) {
                return o.id - id;
            } else {
                return o.claw - claw;
            }
        } else {
            if (o.venom == venom) {
                return o.id - id;
            } else {
                return o.venom - venom;
            }
        }
    }
}
