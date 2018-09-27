package main;

import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class ccc12s4 {


    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int N = in.nextInt();
        while (N != 0) {
            int ans = -1;
            State start = new State(0);


            for (int i = 1; i <= N; ++i) {
                start.coins[i].push(in.nextInt());
            }

            if (N == 1) {
                out.println(0);
                N = in.nextInt();
                continue;
            }

            start.id = start.genID();

            Queue<State> q = new LinkedList<State>();
            q.add(start);
            HashSet<String> vis = new HashSet<String>();

            while (!q.isEmpty()) {
                State cur = q.poll();
                int count = 0;
                for (int i = 1; i <= N+1; ++i) {
                    if (cur.stPeek(i) > cur.stPeek(i - 1)) {
                        ++count;
                    }
                    if (count == N) {
                        ans = cur.dist;
                        break;
                    }
                }
                if (vis.contains(cur.id)) {
                    continue;
                } else {
                    vis.add(cur.id);
                }
//                System.out.println(cur.id + " " + cur.dist);
                if (ans != -1) {
                    break;
                }
                for (int i = 1; i <= N; ++i) {
                    if (i > 1 && cur.stPeek(i) < cur.stPeek(i - 1)) {
                        State next = new State(cur.dist + 1);
                        for (int j = 0; j < cur.coins.length; ++j) {
                            next.coins[j] = (Stack<Integer>) cur.coins[j].clone();
                        }
                        int a = next.stPop(i);
                        if (a != Integer.MAX_VALUE) {
                            next.coins[i - 1].push(a);
                            next.id = next.genID();
                            q.add(next);
                        }
                    }
                    if (i < N && cur.stPeek(i) < cur.stPeek(i + 1)) {
                        State next = new State(cur.dist + 1);
                        for (int j = 0; j < cur.coins.length; ++j) {
                            next.coins[j] = (Stack<Integer>) cur.coins[j].clone();
                        }
                        int a = next.stPop(i);
                        if (a != Integer.MAX_VALUE) {
                            next.coins[i + 1].push(a);
                            next.id = next.genID();
                            q.add(next);
                        }
                    }
                }
            }
            out.println((ans != -1) ? ans : "IMPOSSIBLE");
            N = in.nextInt();
        }
    }
}

class State {
    int dist;
    String id;
    Stack<Integer>[] coins;

    State(int a) {
        dist = a;
        id = "";
        coins = (Stack<Integer>[]) new Stack[9];
        for (int i = 0; i < 9; ++i) {
            coins[i] = new Stack<Integer>();
        }
    }

    int stPeek(int i) {
        if (coins[i].isEmpty()) {
            return Integer.MAX_VALUE;
        } else {
            return coins[i].peek();
        }
    }

    int stPop(int i) {
        if (coins[i].isEmpty()) {
            return Integer.MAX_VALUE;
        } else {
            return coins[i].pop();
        }
    }

    String genID() {
        String res = "";
        boolean first = true;
        for (int i = 0; i < coins.length; ++i) {
            if (first) {
                first = false;
            } else {
                res += "/";
            }
            if (coins[i].isEmpty()) {
                res += "0";
            } else {
                for (Integer elem : coins[i]) {
                    res += elem.toString();
                }
            }
        }
        return res;
    }
}
