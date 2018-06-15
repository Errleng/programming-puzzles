import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

final public class Matrix {
    private final int M;             // number of rows
    private final int N;             // number of columns
    private final double[][] data;   // M-by-N array

    // create M-by-N Matrix of 0's
    public Matrix(int M, int N) {
        this.M = M;
        this.N = N;
        data = new double[M][N];
    }

    // create Matrix based on 2d array
    public Matrix(double[][] data) {
        M = data.length;
        N = data[0].length;
        this.data = new double[M][N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                this.data[i][j] = data[i][j];
    }

    // copy constructor
    private Matrix(Matrix A) {
        this(A.data);
    }

    public double getAtIndex(int row, int column) {
        if (row < this.M && column < this.N)
            return this.data[row][column];
        else {
            System.out.println("Row, column out of bounds: " + row + " " + column);
            throw new ArrayIndexOutOfBoundsException();
        }
    }

    // create and return a random M-by-N Matrix with values between 0 and 1
    public static Matrix random(int M, int N) {
        Matrix A = new Matrix(M, N);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                A.data[i][j] = Math.random();
        return A;
    }

    // create and return the N-by-N identity Matrix
    public static Matrix identity(int N) {
        Matrix I = new Matrix(N, N);
        for (int i = 0; i < N; i++)
            I.data[i][i] = 1;
        return I;
    }

    // swap rows i and j
    private void swap(int i, int j) {
        double[] temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    // create and return the transpose of the invoking Matrix
    public Matrix transpose() {
        Matrix A = new Matrix(N, M);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                A.data[j][i] = this.data[i][j];
        return A;
    }

    // return C = A + B
    public Matrix plus(Matrix B) {
        Matrix A = this;
        if (B.M != A.M || B.N != A.N) throw new RuntimeException("Illegal Matrix dimensions.");
        Matrix C = new Matrix(M, N);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                C.data[i][j] = A.data[i][j] + B.data[i][j];
        return C;
    }


    // return C = A - B
    public Matrix minus(Matrix B) {
        Matrix A = this;
        if (B.M != A.M || B.N != A.N) throw new RuntimeException("Illegal Matrix dimensions.");
        Matrix C = new Matrix(M, N);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                C.data[i][j] = A.data[i][j] - B.data[i][j];
        return C;
    }

    // does A = B exactly?
    public boolean eq(Matrix B) {
        Matrix A = this;
        if (B.M != A.M || B.N != A.N) throw new RuntimeException("Illegal Matrix dimensions.");
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (A.data[i][j] != B.data[i][j]) return false;
        return true;
    }

    // return C = A * B
    public Matrix times(Matrix B) {
        Matrix A = this;
        if (A.N != B.M) throw new RuntimeException("Illegal Matrix dimensions.");
        Matrix C = new Matrix(A.M, B.N);
        for (int i = 0; i < C.M; i++)
            for (int j = 0; j < C.N; j++)
                for (int k = 0; k < A.N; k++)
                    C.data[i][j] += (A.data[i][k] * B.data[k][j]);
        return C;
    }

    public Matrix power(long exp) {
        Matrix original = this;
        Matrix result = this;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = result.times(original);
            }
            original = original.times(original);
            exp /= 2;
        }
        return result;
    }

    // return x = A^-1 b, assuming A is square and has full rank
    public Matrix solve(Matrix rhs) {
        if (M != N || rhs.M != N || rhs.N != 1)
            throw new RuntimeException("Illegal Matrix dimensions.");

        // create copies of the data
        Matrix A = new Matrix(this);
        Matrix b = new Matrix(rhs);

        // Gaussian elimination with partial pivoting
        for (int i = 0; i < N; i++) {

            // find pivot row and swap
            int max = i;
            for (int j = i + 1; j < N; j++)
                if (Math.abs(A.data[j][i]) > Math.abs(A.data[max][i]))
                    max = j;
            A.swap(i, max);
            b.swap(i, max);

            // singular
            if (A.data[i][i] == 0.0) throw new RuntimeException("Matrix is singular.");

            // pivot within b
            for (int j = i + 1; j < N; j++)
                b.data[j][0] -= b.data[i][0] * A.data[j][i] / A.data[i][i];

            // pivot within A
            for (int j = i + 1; j < N; j++) {
                double m = A.data[j][i] / A.data[i][i];
                for (int k = i + 1; k < N; k++) {
                    A.data[j][k] -= A.data[i][k] * m;
                }
                A.data[j][i] = 0.0;
            }
        }

        // back substitution
        Matrix x = new Matrix(N, 1);
        for (int j = N - 1; j >= 0; j--) {
            double t = 0.0;
            for (int k = j + 1; k < N; k++)
                t += A.data[j][k] * x.data[k][0];
            x.data[j][0] = (b.data[j][0] - t) / A.data[j][j];
        }
        return x;
    }

    public Matrix cofactor(int p, int q) {
        Matrix result = new Matrix(this.M-1, this.N-1);
        int k;
        for (int i = 0; i < this.N; i++) {
            for (int j = 0; j < this.N; j++) {
                if (i < p)
                    k = i;
                else if (i > p)
                    k = i - 1;
                else
                    continue;
                if (j < q) {
                    result.data[k][j] = this.data[i][j];
                } else if (j > q) {
                    result.data[k][j-1] = this.data[i][j];
                }
           }
        }
        return result;
    }

    public double determinant() { // Determinant by minors
        if (this.N == 1) {
            return this.data[0][0]; // a
        }

        double result = 0;
        Matrix temp; // Smaller matrix which holds the matrix formed by deleting the i'th row and j'th column
        int sign = 1;

        /* Example
        A = [
        1 2 3
        4 5 6
        7 8 9
        ]
        A(1,1) = [
        5 6
        8 9
        ]
         */

        for (int i = 0; i < this.N; i++) {
            temp = cofactor(0, i);
            result += sign * this.data[0][i] * temp.determinant();
            sign = -sign;
        }
        return result;
    }

    public Matrix adjoint() {
        Matrix result = new Matrix(this.data);
        if (result.N == 1) {
            result.data[0][0] = 1;
            return result;
        }

        Matrix temp;
        int sign = 1;

        for (int i = 0; i < result.N; i++) {
            for (int j = 0; j < result.N; j++) {
                temp = this.cofactor(i, j);
                sign = ((i+j) % 2 == 0) ? 1 : - 1;
                result.data[j][i] = sign * temp.determinant();
            }
        }
        return result;
    }

    public Matrix inverse() {
        Matrix result = new Matrix(this.data);
        double det = result.determinant();
        if (Math.signum(det) == 0) {
            throw new RuntimeException("Inverse of a singular matrix cannot be found");
        }
        Matrix adjoint = result.adjoint();
        for (int i = 0; i < result.N; i++) {
            for (int j = 0; j < result.N; j++) {
                result.data[i][j] = adjoint.data[i][j] / det;
            }
        }
        return result;
    }

    // print Matrix to standard output
    public void show() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                System.out.printf("%1.2f ", this.data[i][j]);
            System.out.println();
        }
    }

    public void showInt() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                System.out.print((int)this.data[i][j] + " ");
            System.out.println();
        }
    }
}
