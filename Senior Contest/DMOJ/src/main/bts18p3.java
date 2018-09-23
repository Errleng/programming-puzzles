package main;

import javafx.scene.layout.Priority;
import main.FastReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class bts18p3 {
    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        int X = in.nextInt();
        PriorityQueue<Integer> participants = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < N; ++i) {
            participants.add(in.nextInt());
        }
        long quality = 0;
        while (X > 0) {
            int val = participants.poll();
            if (val <= 0) {
                break;
            }
            quality += val;
            participants.add(val - 1);
            --X;
        }
        out.println(quality);
    }
}
