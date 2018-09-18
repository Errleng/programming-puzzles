package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class bts18p2 {
    public static int lowerBound(ArrayList<Integer> array, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value <= array.get(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    public static int upperBound(ArrayList<Integer> array, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= array.get(mid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        final int MAX_CHAR = 256;
        String S = in.nextLine();
        int Q = in.nextInt();
        ArrayList<Integer>[] cs = (ArrayList<Integer>[])new ArrayList[MAX_CHAR];
        for (int i = 0; i < MAX_CHAR; ++i) {
            cs[i] = new ArrayList<>();
        }
        for (int i = 0; i < S.length(); ++i) {
            cs[S.charAt(i)].add(i + 1);
        }
        for (int i = 0; i < Q; ++i) {
            int a = in.nextInt();
            int b = in.nextInt();
            char c = in.next().charAt(0);
            if (cs[c].size() == 0) {
                out.println(0);
                continue;
            }
            int first = lowerBound(cs[c], cs[c].size(), a);
            int last = upperBound(cs[c], cs[c].size(), b);
            int freq = last - first;
            out.println(freq);
        }
    }
}
