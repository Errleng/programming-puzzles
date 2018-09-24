import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.DataInputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ccc09s4 solver = new ccc09s4();
        solver.solve(1, in, out);
        out.close();
    }

    static class ccc09s4 {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int N = in.nextInt();
            int T = in.nextInt();
            int[] pencilCost = new int[N];
            Arrays.fill(pencilCost, -1);
            int[] dists = new int[N];
            Arrays.fill(dists, Integer.MAX_VALUE);
            ArrayList<Edge>[] adj = new ArrayList[N];

            for (int i = 0; i < N; ++i) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < T; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                int c = in.nextInt();
                adj[x].add(new Edge(y, c));
                adj[y].add(new Edge(x, c));
            }
            int K = in.nextInt();
            for (int i = 0; i < K; ++i) {
                pencilCost[in.nextInt() - 1] = in.nextInt();
            }

            int D = in.nextInt() - 1;

            dists[D] = 0;
            int min = Integer.MAX_VALUE;
            boolean[] vis = new boolean[N];
            Queue<Edge> q = new LinkedList<>();
            for (int i = 0; i < N; ++i) {
                int m = -1;
                for (int j = 0; j < N; ++j) {
                    if (!vis[j] && m == -1 || !vis[j] && dists[j] < dists[m]) {
                        m = j;
                    }
                }
                if (dists[m] >= min) {
                    break;
                }
                vis[m] = true;
                for (Edge e : adj[m]) {
                    dists[e.u] = Math.min(dists[e.u], e.cost + dists[m]);
                }
                if (pencilCost[m] != -1) {
                    min = Math.min(min, dists[m] + pencilCost[m]);
                }
            }
            out.println(min);
        }

    }

    static class Edge implements Comparable<Edge> {
        int u;
        int cost;

        Edge(int a, int b) {
            u = a;
            cost = b;
        }

        public int compareTo(Edge o) {
            return Integer.compare(o.cost, cost);
        }

    }

    static class FastReader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer;
        private int bytesRead;

        public FastReader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public FastReader(InputStream inputStream) {
            din = new DataInputStream(inputStream);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public FastReader(String file_name) {
            try {
                din = new DataInputStream(new FileInputStream(file_name));
            } catch (IOException e) {
                e.printStackTrace();
            }
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public int nextInt() {
            int ret = 0;
            try {
                byte c = read();
                while (c <= ' ')
                    c = read();
                boolean neg = (c == '-');
                if (neg)
                    c = read();
                do {
                    ret = ret * 10 + c - '0';
                } while ((c = read()) >= '0' && c <= '9');

                if (neg)
                    return -ret;
            } catch (IOException e) {
                e.printStackTrace();
            }
            return ret;
        }

        private void fillBuffer() throws IOException {
            try {
                bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

    }
}

