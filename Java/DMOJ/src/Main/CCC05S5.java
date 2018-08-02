package Main;

import java.io.PrintWriter;
import java.util.Arrays;

public class CCC05S5 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        double ans = 0;
        int T = in.nextInt();
        BIT FT = new BIT(T);
        Elem[] scores = new Elem[T];
        for (int i = 0; i < T; i++) {
            scores[i] = new Elem(i, in.nextInt());
        }
        Arrays.sort(scores, (a, b) -> a.val - b.val);
        for (int i = T - 1; i > -1; i--) {
            FT.update(scores[i].idx + 1, 1);
            ans += FT.query(scores[i].idx + 1);
        }
        ans /= T;
        out.printf("%.2f\n", ans-1e-9);
    }
}

class BIT {
    int[] Arr;

    public BIT(int size) {
        Arr = new int[size];
        for (int i = 1; i <= size; i++) {
            this.update(i, Arr[i - 1]);
        }
    }

    public BIT(int[] inArr) {
        Arr = new int[inArr.length];
        for (int i = 0; i < inArr.length; i++) {
            Arr[i] = inArr[i];
        }
        for (int i = 1; i <= inArr.length; i++) {
            this.update(i, Arr[i - 1]);
        }
    }

    public void update(int i, int add) {
        while (i <= Arr.length) {
            Arr[i - 1] += add;
            i += i & (-i);
        }
    }

    public int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += Arr[i - 1];
            i -= i & (-i);
        }
        return sum;
    }
}

class Elem {
    int val, idx;

    Elem(int a, int b) {
        this.idx = a;
        this.val = b;
    }
}