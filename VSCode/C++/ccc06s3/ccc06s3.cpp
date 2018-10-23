#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#include "../Library/debug.h"

#define repn(i, j, k, step) for (int i = j; i < k; i += step)
#define rrepn(i, j, k, step) for (int i = j; i >= k; i -= step)
#define rep(i, j) repn(i, 0, j, 1)
#define srep(i, j, k) repn(i, j, k, 1)
#define rrep(i, j) rrepn(i, j, 0, 1)
#define foreach(i, container) for (auto i : container)
#define mem(a, b) memset((a), (b), sizeof(a))

#define fi first
#define se second
#define pb push_back

#define INF 0x3f3f3f3f

// clang-format off
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// clang-format on

using namespace std;

struct Point {
    int x, y;
};

struct Line {
    Point p1, p2;
};

Point sub(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }

int CrPr(Point a, Point b) { return a.x * b.y - a.y * b.x; }

bool eq(Point a, Point b) { return a.x == b.x && a.y == b.y; }

bool intersect(Line a, Line b) {
    Point r = sub(a.p2, a.p1);
    Point s = sub(b.p2, b.p1);
    int num = CrPr(sub(b.p1, a.p1), r);
    int den = CrPr(r, s);
    if (den == 0) {
        if (num != 0) {
            return false;
        }
        if (eq(a.p1, b.p1) || eq(a.p2, b.p2) || eq(a.p1, b.p2) ||
            eq(a.p2, b.p1)) {
            return true;
        }

        bool dir_x[] = {(b.p1.x - a.p1.x < 0), (b.p1.x - a.p2.x < 0),
                        (b.p2.x - a.p1.x < 0), (b.p2.x - a.p2.x < 0)};
        bool dir_y[] = {(b.p1.y - a.p1.y < 0), (b.p1.y - a.p2.y < 0),
                        (b.p2.y - a.p1.y < 0), (b.p2.y - a.p2.y < 0)};

        return !all_of(begin(dir_x), end(dir_x),
                       [dir_x](bool x) { return x == dir_x[0]; }) ||
               !all_of(begin(dir_y), end(dir_y),
                       [dir_y](bool x) { return x == dir_y[0]; });
    }
    double u = (double)num / (double)den;
    double t = CrPr(sub(b.p1, a.p1), s) / (double)den;
    return t >= 0 && t <= 1 && u >= 0 && u <= 1;
}

int r_x, r_y, j_x, j_y, N, n, a, b, ans;

int main() {
    scanf("%d %d %d %d", &r_x, &r_y, &j_x, &j_y);
    scan(N);
    Line los = {{r_x, r_y}, {j_x, j_y}};
    rep(i, N) {
        scan(n);
        vector<Line> lines(n);
        vector<Point> points(n);
        rep(j, n) {
            scan(a);
            scan(b);
            points[j] = {a, b};
        }
        Line l;
        rep(j, points.size() - 1) {
            l.p1 = {points[j].x, points[j].y};
            l.p2 = {points[j + 1].x, points[j + 1].y};
            lines[j] = l;
        }
        l.p1 = {a, b};
        l.p2 = {lines[0].p1.x, lines[0].p1.y};
        lines[lines.size() - 1] = l;
        rep(j, lines.size()) {
            if (intersect(los, lines[j])) {
                ++ans;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}