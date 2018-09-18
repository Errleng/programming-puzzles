package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.Arrays;

import static java.lang.Math.abs;
import static java.lang.Math.sqrt;

public class coci07c6p3 {
    static int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int N = in.nextInt();
        int[] nums = new int[N];
        int hcf = 0;
        nums[0] = in.nextInt();
        for (int i = 1; i < N; ++i) {
            nums[i] = in.nextInt();
            hcf = gcd(abs(nums[i] - nums[i-1]), hcf);
        }
        for (int i = 2; i * i <= hcf; ++i) {
            if (hcf % i == 0) {
                out.print(i + " ");
                if (i != hcf / i) {
                    out.print((hcf / i) + " ");
                }
            }
        }
        out.println(hcf);
    }
}
