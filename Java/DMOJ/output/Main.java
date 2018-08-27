import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.Set;
import java.io.IOException;
import java.util.HashMap;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        fibonacci2 solver = new fibonacci2();
        solver.solve(1, in, out);
        out.close();
    }

    static class fibonacci2 {
        public static BigInteger TWO = new BigInteger("2");
        public static BigInteger THREE = new BigInteger("3");
        public static BigInteger FIVE = new BigInteger("5");

        public static BigInteger lcm(BigInteger a, BigInteger b) {
            BigInteger temp = a.gcd(b);
            if (temp.equals(BigInteger.ZERO)) {
                return BigInteger.ZERO;
            } else {
                return (a.divide(temp).multiply(b));
            }
        }

        public static BigInteger sqrt(BigInteger x) {
            BigInteger div = BigInteger.ZERO.setBit(x.bitLength() / 2);
            BigInteger div2 = div;
            // Loop until we hit the same value twice in a row, or wind
            // up alternating.
            for (; ; ) {
                BigInteger y = div.add(x.divide(div)).shiftRight(1);
                if (y.equals(div) || y.equals(div2))
                    return y;
                div2 = div;
                div = y;
            }
        }

        public static ArrayList<BigInteger> divisors(BigInteger N) {
            ArrayList<BigInteger> res = new ArrayList<BigInteger>();
            for (BigInteger i = BigInteger.ONE; i.compareTo(sqrt(N)) <= 0; i = i.add(BigInteger.ONE)) {
                if (N.mod(i).equals(BigInteger.ZERO)) {
                    if (N.divide(i).equals(i)) {
                        res.add(i);
                    } else {
                        res.add(i);
                        res.add(N.divide(i));
                    }
                }
            }
            return res;
        }

        public static ArrayList<BigExp> prime_factorize(BigInteger N) {
            HashMap<BigInteger, Integer> exp = new HashMap<>();
            while (N.mod(TWO).equals(BigInteger.ZERO)) {
                Integer val = exp.get(TWO);
                if (val != null) {
                    exp.put(TWO, val + 1);
                } else {
                    exp.put(TWO, 1);
                }
                N = N.divide(TWO);
            }
            for (BigInteger i = THREE; i.compareTo(sqrt(N)) <= 0; i = i.add(TWO)) {
                while (N.mod(i).equals(BigInteger.ZERO)) {
                    Integer val = exp.get(i);
                    if (val != null) {
                        exp.put(i, val + 1);
                    } else {
                        exp.put(i, 1);
                    }
                    N = N.divide(i);
                }
            }
            if (N.compareTo(TWO) > 0) {
                Integer val = exp.get(N);
                if (val != null) {
                    exp.put(N, val + 1);
                } else {
                    exp.put(N, 1);
                }
            }
            ArrayList<BigExp> res = new ArrayList<BigExp>();
            Iterator it = exp.entrySet().iterator();
            while (it.hasNext()) {
                Map.Entry pair = (Map.Entry) it.next();
                res.add(new BigExp((BigInteger) pair.getKey(), (Integer) pair.getValue()));
                it.remove();
            }
            return res;
        }

        public static BigInteger prime_power_divisor(BigInteger p, int k) {
            if (k == 0)
                return BigInteger.ONE;
            else if (p.equals(FIVE))
                return (p.pow(k - 1)).multiply(FIVE);
            BigInteger e = (p.mod(FIVE).equals(TWO) || p.mod(FIVE).equals(THREE)) ? BigInteger.ONE : new BigInteger("-1");
            for (BigInteger i : divisors(p.add(e))) {
                if (fib_mod(i, p).equals(BigInteger.ZERO)) {
                    return i.multiply(p.pow(k - 1));
                }
            }
            throw new RuntimeException("Prime power divisor not found. p = " + p.toString() + " k = " + k);
        }

        public static BigInteger pisano_period(BigInteger N) {
            if (N.compareTo(BigInteger.ZERO) < 1)
                return BigInteger.ZERO;
            else if (N.equals(BigInteger.ONE))
                return BigInteger.ONE;
            BigInteger d = BigInteger.ONE;
            ArrayList<BigExp> pf = prime_factorize(N);
            for (BigExp i : pf) {
                d = lcm(d, prime_power_divisor(i.f, i.s));
//            System.out.println("(" + i.f.toString() + "," + i.s + ") " + prime_power_divisor(i.f, i.s).toString() + ": " + d.toString());
            }
            BigInteger t = BigInteger.ZERO;
            for (int i = 0; i < 3; ++i) {
                t = d.shiftLeft(i);
                if (fib_mod(t, N).equals(BigInteger.ZERO) && fib_mod(t.add(BigInteger.ONE), N).equals(BigInteger.ONE)) {
                    return t;
                }
            }
            throw new java.lang.RuntimeException("CONJECTURE DISPROVEN WITH N = " + N.toString() + ", d = " + d.toString() + ", t = " + t.toString());
        }

        public static BigInteger fib_mod(BigInteger N, BigInteger m) {
            BigInteger f = BigInteger.ZERO;
            BigInteger g = BigInteger.ONE;
            BigInteger a = BigInteger.ZERO;
            BigInteger b = BigInteger.ONE;
            for (int i = 0; i <= N.bitLength(); i++) {
                if (N.testBit(i)) {
                    BigInteger t = f;
                    f = ((f.multiply(a)).add(g.multiply(b))).mod(m);
                    g = ((t.multiply(b)).add(g.multiply(a.add(b)))).mod(m);
                }
                BigInteger t = a;
                a = ((a.multiply(a)).add(b.multiply(b))).mod(m);
                b = ((t.multiply(b)).add(b.multiply(t.add(b)))).mod(m);
            }
            return f;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            BigInteger N = new BigInteger(in.next());
            BigInteger M = new BigInteger(in.next());
            out.print(fib_mod(N, M));
            out.print(" ");
            out.print(pisano_period(M));

            int LIMIT = 11;
            for (int i = 2; i <= LIMIT; i++) {
                for (int j = 2; j <= LIMIT; j++) {
                    BigInteger test = BigInteger.valueOf(i).pow(j);
                    System.out.print(pisano_period(test).toString() + " ");
//                System.out.println(test.toString() + ": " + pisano_period(test).toString());
                }
            }
            System.out.println();
//        N = new BigInteger("31381059609");
//        BigInteger D = new BigInteger("41841412812");
//        for (int i = 0; i < 3; i++) {
//            BigInteger T = D.shiftLeft(i);
//            System.out.println(T.toString() + ": " + fib_mod(T, N).toString() + " " + fib_mod(T.add(BigInteger.ONE), N).toString());
//        }
        }

    }

    static class BigExp {
        BigInteger f;
        int s;

        BigExp(BigInteger a, int b) {
            this.f = a;
            this.s = b;
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream IS) {
            br = new BufferedReader(new
                    InputStreamReader(IS));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

    }
}

