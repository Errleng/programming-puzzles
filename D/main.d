import std.datetime.stopwatch;

import std.stdio;
import std.conv;
import std.container;
import std.math;
import std.typecons;
import std.string;
import std.algorithm;

void wvarln(T...)(T args) {
    foreach (arg; args) {
        write(arg, " ");
    }
    writeln();
}

void wvar(T...)(T args) {
    foreach (arg; args) {
        write(arg, " ");
    }
}

struct point {
    int r, c;
    this(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

long take_photos(int n, int m, int k, int[] r, int[] c) {
    const int INF = to!int(1e9);
    int[][] dp = new int[][](n+1, k+1);
    point[] ps;
    foreach (i; 0..n) {
        ps ~= point(r[i], c[i]);
    }
    wvarln(ps);
    ps.sort!("a.r < b.r");
    wvarln(ps);
    foreach (i; 1..n+1) {
        foreach (j; 0..k+1) {
            dp[i][j] = INF;
        }
    }
    wvarln(dp);
    foreach (i; 1..n+1) {
        foreach (j; 1..k+1) {
            foreach (t; 0..i) {
                dp[i][j] = min(dp[i][j], dp[t][j-1] + pow((ps[i].r - ps[t].c + 1), 2));
            }
        }
    }
    wvarln(dp);
    return dp[n][k];
}

void solve() {
    long ans = take_photos(5, 7, 2, [0, 4, 4, 4, 4], [3, 4, 6, 5, 6]);
    wvarln("Answer:", ans);
}

void main() {
    stdin.reopen("input.txt", "r");
    auto timer = benchmark!(solve)(1);
    auto resTime = timer[0];
    writeln("\nTime: ", resTime);
}