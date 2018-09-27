import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.DataInputStream;
import java.util.Collection;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.Stack;
import java.util.HashSet;
import java.util.Vector;
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
        ccc12s4 solver = new ccc12s4();
        solver.solve(1, in, out);
        out.close();
    }

    static class ccc12s4 {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int N = in.nextInt();
            while (N != 0) {
                int ans = -1;
                State start = new State(0);


                for (int i = 1; i <= N; ++i) {
                    start.coins[i].push(in.nextInt());
                }

                if (N == 1) {
                    out.println(0);
                    N = in.nextInt();
                    continue;
                }

                start.id = start.genID();

                Queue<State> q = new LinkedList<State>();
                q.add(start);
                HashSet<String> vis = new HashSet<String>();

                while (!q.isEmpty()) {
                    State cur = q.poll();
                    int count = 0;
                    for (int i = 1; i <= N + 1; ++i) {
                        if (cur.stPeek(i) > cur.stPeek(i - 1)) {
                            ++count;
                        }
                        if (count == N) {
                            ans = cur.dist;
                            break;
                        }
                    }
                    if (vis.contains(cur.id)) {
                        continue;
                    } else {
                        vis.add(cur.id);
                    }
//                System.out.println(cur.id + " " + cur.dist);
                    if (ans != -1) {
                        break;
                    }
                    for (int i = 1; i <= N; ++i) {
                        if (i > 1 && cur.stPeek(i) < cur.stPeek(i - 1)) {
                            State next = new State(cur.dist + 1);
                            for (int j = 0; j < cur.coins.length; ++j) {
                                next.coins[j] = (Stack<Integer>) cur.coins[j].clone();
                            }
                            int a = next.stPop(i);
                            if (a != Integer.MAX_VALUE) {
                                next.coins[i - 1].push(a);
                                next.id = next.genID();
                                q.add(next);
                            }
                        }
                        if (i < N && cur.stPeek(i) < cur.stPeek(i + 1)) {
                            State next = new State(cur.dist + 1);
                            for (int j = 0; j < cur.coins.length; ++j) {
                                next.coins[j] = (Stack<Integer>) cur.coins[j].clone();
                            }
                            int a = next.stPop(i);
                            if (a != Integer.MAX_VALUE) {
                                next.coins[i + 1].push(a);
                                next.id = next.genID();
                                q.add(next);
                            }
                        }
                    }
                }
                out.println((ans != -1) ? ans : "IMPOSSIBLE");
                N = in.nextInt();
            }
        }

    }

    static class State {
        int dist;
        String id;
        Stack<Integer>[] coins;

        State(int a) {
            dist = a;
            id = "";
            coins = (Stack<Integer>[]) new Stack[9];
            for (int i = 0; i < 9; ++i) {
                coins[i] = new Stack<Integer>();
            }
        }

        int stPeek(int i) {
            if (coins[i].isEmpty()) {
                return Integer.MAX_VALUE;
            } else {
                return coins[i].peek();
            }
        }

        int stPop(int i) {
            if (coins[i].isEmpty()) {
                return Integer.MAX_VALUE;
            } else {
                return coins[i].pop();
            }
        }

        String genID() {
            String res = "";
            boolean first = true;
            for (int i = 0; i < coins.length; ++i) {
                if (first) {
                    first = false;
                } else {
                    res += "/";
                }
                if (coins[i].isEmpty()) {
                    res += "0";
                } else {
                    for (Integer elem : coins[i]) {
                        res += elem.toString();
                    }
                }
            }
            return res;
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

