import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.DataInputStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.AbstractCollection;
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
        sssp solver = new sssp();
        solver.solve(1, in, out);
        out.close();
    }

    static class sssp {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int N = in.nextInt();
            int M = in.nextInt();
            int[] dist = new int[N];
            Arrays.fill(dist, Integer.MAX_VALUE);
            ArrayList<Edge>[] adj = new ArrayList[N];
            for (int i = 0; i < N; ++i) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < M; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                int c = in.nextInt();
                adj[a].add(new Edge(b, c));
                adj[b].add(new Edge(a, c));
            }
            PriorityQueue<Edge> q = new PriorityQueue<>();
            dist[0] = 0;
            q.add(new Edge(0, 0));
            while (!q.isEmpty()) {
                Edge u = q.poll();
                for (Edge e : adj[u.id]) {
                    int nd = dist[u.id] + e.w;
                    if (nd < dist[e.id]) {
                        dist[e.id] = nd;
                        q.add(new Edge(e.id, nd));
                    }
                }
            }
            for (int i = 0; i < N; ++i) {
                if (dist[i] == Integer.MAX_VALUE) {
                    out.println(-1);
                } else {
                    out.println(dist[i]);
                }
            }
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

    static class Edge implements Comparable<Edge> {
        int id;
        int w;

        Edge(int a, int b) {
            id = a;
            w = b;
        }

        public int compareTo(Edge o) {
            return Integer.compare(o.w, w);
        }

    }
}

