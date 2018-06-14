import java.util.concurrent.ConcurrentHashMap;

public class fibonacci {
    static long fibMatExp(long n) {
        double[][] baseMat = {{1, 1}, {1, 0}};
        Matrix A = new Matrix(baseMat);
        A = A.power(n-2);
        return (long)A.getAtIndex(0,0);
    }

    static long fibMemoDerivation(long n) {
        ConcurrentHashMap<Long, Long> memo = new ConcurrentHashMap<>();
        return fibMemoHelper(memo, n);
    }

    private static long fibMemoHelper(ConcurrentHashMap<Long, Long> memo, long n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1 || n == 2) {
            memo.put(n, (long)1);
            return memo.get(n);
        }

        if (memo.containsKey(n))
            return memo.get(n);

        long k;

        if ((n & 1) == 0) {
            k = n / 2;
            long res = (2 * fibMemoHelper(memo, k-1) + fibMemoHelper(memo, k)) * fibMemoHelper(memo, k);
            memo.put(n, res);
            return memo.get(n);
        }
        else {
            k = (n + 1) / 2;
            long res = fibMemoHelper(memo, k) * fibMemoHelper(memo, k) + fibMemoHelper(memo, k-1) * fibMemoHelper(memo, k-1);
            memo.put(n, res);
            return memo.get(n);
        }
    }
}
