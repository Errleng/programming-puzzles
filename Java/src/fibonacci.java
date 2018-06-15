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

    public static void binetProof() {
        double[][] arr_A = {
                {8, 11, 2, 8},
                {0, -7, 2, -1},
                {-3, -7, 2, 1},
                {1, 1, 2, 4}
        };
        double[][] arr_B = {
                {1, -2, 0, 5},
                {0, 7, 1, 5},
                {0, 4, 4, 0},
                {0, 0, 0, 2}
        };
        Matrix A = new Matrix(arr_A);
        Matrix B = new Matrix(arr_B);
        A.show();
        System.out.println();
        B.show();
        System.out.println();
        System.out.println(A.determinant());
        System.out.println();
        Matrix C = A.times(A.inverse());
        C.show();
        System.out.println();
    }
}
