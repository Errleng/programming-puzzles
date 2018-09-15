package Main;

import Main.FastScanner;
import java.io.PrintWriter;

public class ccc15s3 {
    int find(int[] arr, int x) {
        while (x != arr[x]) {
            arr[x] = arr[arr[x]];
            x = arr[x];
        }
        return x;
    }

    void unite(int[] arr, int x, int y) {
        int top_x = find(arr, x);
        int top_y = find(arr, y);
        arr[top_x] = top_y;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int G = in.nextInt();
        int P = in.nextInt();
        int[] d = new int[G+1];
        for (int i = 0; i < G + 1; ++i) {
            d[i] = i;
        }
        for (int i = 0; i < P; ++i) {
            int g = in.nextInt();
            int top = find(d, g);
            if (top == 0) {
                out.println(i);
                return;
            }
            unite(d, top, top - 1);
        }
        out.println(P);
    }
}
