package main;

import main.FastReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class vmss7wc15c3p2 {
    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        int K = in.nextInt();
        int[] scores = new int[N];
        for (int i = 0; i < N; ++i) {
            scores[i] = in.nextInt();
        }
        Arrays.sort(scores);
        int sum = 0;
        int count = 0;
        for (int i = N - 1; count < K; --i) {
            if (scores[i] < 0) {
                break;
            }
            sum += scores[i];
            ++count;
        }
        out.println(sum);
    }
}
