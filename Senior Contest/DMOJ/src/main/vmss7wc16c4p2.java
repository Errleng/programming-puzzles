package main;

import main.FastReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

public class vmss7wc16c4p2 {

    static ArrayList<String>[] sets;
    static ArrayList<String> strings;
    static int N;
    static int L;

    public void makeWords(String s, int go) {
        if (s.length() <= L) {
            if (go == N) {
                strings.add(s);
            } else {
                makeWords(s, go + 1);
                for (String c : sets[go]) {
                    makeWords(s + c, go + 1);
                }
            }
        }
    }

    public void solve(int testNumber, FastReader in, PrintWriter out) {
        N = in.nextInt();
        L = in.nextInt();
        strings = new ArrayList<>();
        sets = new ArrayList[N];
        for (int i = 0; i < N; ++i) {
            sets[i] = new ArrayList<>();
        }
        for (int i = 0; i < N; ++i) {
            int M = in.nextInt();
            for (int j = 0; j < M; ++j) {
                sets[i].add(in.next());
            }
        }

        for (String c : sets[0]) {
            makeWords(c, 1);
        }

        Collections.sort(strings);
        for (String s : strings) {
            out.println(s);
        }
    }
}
