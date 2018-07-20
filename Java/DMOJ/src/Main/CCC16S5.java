package Main;

import java.io.PrintWriter;
import java.util.Scanner;

public class CCC16S5 {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int N;
        long T;
        N = in.nextInt();
        T = in.nextLong();
        char[] startState = in.next().toCharArray();
        int[] state = new int[startState.length];
        for (int i = 0; i < startState.length; ++i) {
            state[i] = startState[i] - '0';
        }
        while (T > 0) {
            long LB = maxPow(2, T);
            state = simulate(state, LB);
            T -= LB;
        }
        for (int i = 0; i < state.length; ++i) {
            out.print(state[i]);
        }
    }

    long maxPow(int b, long n) {
        int e = (int) (Math.log(n) / Math.log(b));
        return (int) (Math.pow(b, e));
    }

    int[] simulate(int[] curState, long generations) {
        int[] res = new int[curState.length];
        for (int i = 0; i < curState.length; ++i) {
            int a = (int) (i + generations) % curState.length;
            int b = (int) (i - generations) % curState.length;
            if (b < 0) b += curState.length;
            res[i] = curState[a] ^ curState[b];
        }
        return res;
    }
}
