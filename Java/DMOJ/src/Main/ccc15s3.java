package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.TreeSet;

import static java.lang.Math.max;

public class ccc15s3 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int G = in.nextInt();
        int P = in.nextInt();
        ArrayList<Integer> remaining = new ArrayList<>();
        for (int i = 0; i < G; i++) {
            remaining.add(i);
        }
        for (int i = 0; i < P && remaining.size() > 0; i++) {
            int g = in.nextInt() - 1;
            int lo = 0;
            int hi = remaining.size() - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (g < remaining.get(mid)) {
                    hi = mid - 1;
                } else if (g > remaining.get(mid)) {
                    lo = mid + 1;
                } else {
                    lo = mid + 1;
                    break;
                }
            }
            if (lo > 0)
                lo -= 1;
            if (remaining.get(lo) <= g) {
                remaining.remove(lo);
            } else {
                out.println(i);
                return;
            }
        }
        out.println(P);
    }
}
