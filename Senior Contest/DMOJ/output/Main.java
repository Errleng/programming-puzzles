import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.Collections;
import java.util.ArrayList;
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
        vmss7wc16c4p2 solver = new vmss7wc16c4p2();
        solver.solve(1, in, out);
        out.close();
    }

    static class vmss7wc16c4p2 {
        static ArrayList<String>[] sets;
        static ArrayList<String> strings;
        static int N;
        static int L;

        public void makeWords(String s, int go) {
            if (s.length() <= L) {
                if (go == N) {
                    strings.add(s);
                } else {
                    makeWords(s, go + 1);
                    for (String c : sets[go]) {
                        makeWords(s + c, go + 1);
                    }
                }
            }
        }

        public void solve(int testNumber, FastReader in, PrintWriter out) {
            N = in.nextInt();
            L = in.nextInt();
            strings = new ArrayList<>();
            sets = new ArrayList[N];
            for (int i = 0; i < N; ++i) {
                sets[i] = new ArrayList<>();
            }
            for (int i = 0; i < N; ++i) {
                int M = in.nextInt();
                for (int j = 0; j < M; ++j) {
                    sets[i].add(in.next());
                }
            }

            for (String c : sets[0]) {
                makeWords(c, 1);
            }

            Collections.sort(strings);
            for (String s : strings) {
                out.println(s);
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

        String next() {
            byte[] buf = new byte[64];
            int cnt = 0, c;
            try {
                c = read();
                while (c <= ' ')
                    c = read();
                buf[cnt++] = (byte) c;
                while ((c = read()) > ' ') {
                    buf[cnt++] = (byte) c;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return new String(buf, 0, cnt);
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

