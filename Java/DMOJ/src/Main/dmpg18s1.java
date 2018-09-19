package Main;

import Main.FastScanner;
import java.io.PrintWriter;
import java.util.Stack;

public class dmpg18s1 {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.nextLine();
        Stack<Integer> track = new Stack<>();
        int[] cnt = new int[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            if (i != 0 && track.isEmpty()) {
                out.println("Invalid");
                return;
            }
            if (!track.isEmpty()) {
                ++cnt[track.peek()];
            }
            if (!track.isEmpty() && cnt[track.peek()] == s.charAt(track.peek()) - '0') {
                track.pop();
            }
            if (s.charAt(i) != '0') {
                track.push(i);
            }
        }
        if (track.isEmpty()) {
            out.println("Valid");
        } else {
            out.println("Invalid");
        }
    }
}
