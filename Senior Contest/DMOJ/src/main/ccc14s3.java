package main;

import main.FastReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Stack;

public class ccc14s3 {
    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int T = in.nextInt();
        for (int i = 0; i < T; ++i) {
            int N = in.nextInt();
            Stack<Integer> cars = new Stack<>();
            Stack<Integer> branch = new Stack<>();
            int order = 1;

            for (int j = 0; j < N; ++j) {
                cars.push(in.nextInt());
            }

            while (!cars.isEmpty()) {
                int top = cars.pop();
                if (top == order) {
                    ++order;
                } else {
                    branch.push(top);
                }
                while (!branch.isEmpty()) {
                    if (branch.peek() != order) {
                        break;
                    }
                    ++order;
                    branch.pop();
                }
            }
            boolean possible = branch.isEmpty();

            if (possible) {
                out.println("Y");
            } else {
                out.println("N");
            }
        }
    }
}
