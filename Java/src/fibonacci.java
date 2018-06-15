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
        A.showInt();
        System.out.println();
        B.showInt();
        System.out.println();
        // Determinant
        System.out.println(A.determinant()); // Factor that an area is scaled after applying the matrix's transformation
        System.out.println();

        // Inverse matrices
        double[][] arr_C = {
                {-3, 6},
                {2, -5}
        };
        Matrix C = new Matrix(arr_C);
        C.showInt();
        System.out.println();
        C.inverse().show();
        System.out.println();
        C.times(C.inverse()).show();
        System.out.println();

        // Change of Basis
        double[][] arr_jennifer_basis = { // Consists of Jennifer's basis vectors
                {2, -1},
                {1, 1}
        };
        double[][] arr_jennifer_vector = {
                {-1},
                {2}
        };
        double[][] arr_our_vector = {
                {3},
                {2}
        };
        double[][] arr_rotation_90_ccw = {
                {0, -1},
                {1, 0}
        };
        Matrix jenV = new Matrix(arr_jennifer_vector);
        Matrix ourV = new Matrix(arr_our_vector);
        Matrix jenniferBasis = new Matrix(arr_jennifer_basis); // Transformation Jennifer's vector into ours
        Matrix rotation90CCW = new Matrix(arr_rotation_90_ccw);
        jenniferBasis.times(jenV).show(); // Jennifer's vector in our coordinate system
        System.out.println();
        jenniferBasis.inverse().times(ourV).show(); // Transforms our vector into Jennifer's coordinate system
        System.out.println();
        jenniferBasis.inverse().times(rotation90CCW.times(jenniferBasis.times(jenV))).show();
        // What's going on here?
        // Translate Jennifer's vector into our coordinate system
        // Apply transformation matrix to that vector
        // Translate the resulting transformed vector into Jennifer's coordinate system
        // inv(A) * M * A

        // Eigenvectors and Eigenvalues
        // After a transformation (multiplying by a matrix), the eigenvector stays on its own span line (AKA doesn't change direction to the side)
        // A * v = lambda * v (v = eigenvector, lambda = eigenvalue)
        // lambda is currently a scalar, but it can also be represented as a matrix
        // lambda = diagonal matrix where the diagonal values are lambda. AKA lambda * identity matrix
        // It has the same effect as multiplying by lambda as a scalar
        // lambda = l * I where I is the identity matrix and l is lambda
        // Now that lambda is a matrix composition, it can be used in matrix operations
        // A * v - (l * I) * v = 0
        // (A - l) * v = 0
        /*
        Matrix Example
        [
        2 - l, 2;
        1, 3 - l
        ]
        */
        // For a non-zero eigenvector v, det(A - l) must therefore be 0

    }
}
