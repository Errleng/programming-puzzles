package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.Arrays;

public class dmpg18s2 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int N = in.nextInt();
        int[] array = new int[N + 1];
        int[] sums = new int[N + 1];
        for (int i = 1; i <= N; ++i) {
            array[i] = in.nextInt();
        }
        for (int i = 1; i <= N; ++i) {
            sums[i] = sums[i - 1] + array[i];
        }
        long ans = 0;
        System.out.println(Arrays.toString(sums));
        for (int i = 1; i <= N; ++i) {
            ans += sums[N - (i - 1)] - sums[i - 1];
            out.println(ans);
        }
    }
}
