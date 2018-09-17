import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        tsoc15c2p5 solver = new tsoc15c2p5();
        solver.solve(1, in, out);
        out.close();
    }

    static class tsoc15c2p5 {
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

    static class Bebilith implements Comparable<Bebilith> {
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

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream IS) {
            br = new BufferedReader(new
                    InputStreamReader(IS));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

