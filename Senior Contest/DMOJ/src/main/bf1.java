package main;

import main.FastReader;

import java.io.IOException;
import java.io.PrintWriter;

public class bf1 {
    public void solve(int testNumber, FastReader in, PrintWriter out)  {
        int size = in.nextInt();
        int[] list = new int[size];
        for (int i = 0; i < size; ++i) {
            list[i] = in.nextInt();
        }
        int min;
        int min_index;
        for (int j = 0; j < size; j++) {
            min = Integer.MAX_VALUE;
            min_index = -1;
            for (int i = 0; i < size; ++i) {
                if (min > list[i]) {
                    min = list[i];
                    min_index = i;
                }
            }
            list[min_index] = Integer.MAX_VALUE;
            out.println(min);
        }
    }
}
