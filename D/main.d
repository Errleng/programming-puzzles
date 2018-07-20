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

struct DisjointSet {
	int S;
	int[] par, rank;
	this(int size) {
		this.S = size;
		this.par.length = size;
		this.rank.length = size;
	}
	void init() {
		foreach(i; 0..S)
			this.par[i] = i;
	}
	int find(int a) {
		if (par[a] != a) {
			par[a] = this.find(par[a]);
		}
		return par[a];
	}
	void unite(int a, int b) {
		int ra = this.find(a);
		int rb = this.find(b);
		if (ra != rb) {
			if (rank[ra] < rank[rb]) {
				par[ra] = rb;
			} else if (rank[rb] < rank[ra]) {
				par[rb] = ra;
			} else {
				par[rb] = ra;
				rank[ra]++;
			}
		}
	}
}
void solve() {
	alias tup = Tuple!(long, int, int, bool);
	
	int N, M, P, Q;
    scanf("%d %d %d %d", &N, &M, &P, &Q);

    tup[] edges;
    DisjointSet Pl = DisjointSet(N);
    DisjointSet Ci = DisjointSet(M);
    Pl.init();
    Ci.init();

    int a, b;
    long c;

    long total = 0, saved = 0;

    foreach(p; 0..P) {
        scanf("%d %d %d", &a, &b, &c);
        --a; --b;
        edges ~= tup(c, a, b, true);
        total += c * N;
    }
    foreach(q; 0..Q) {
        scanf("%d %d %d", &a, &b, &c);
        --a; --b;
        edges ~= tup(c, a, b, false);
        total += c * M;
    }

    auto bh = heapify!"a > b"(edges);
    int remPl = N, remCi = M;
    tup e;
    while (!bh.empty) {
        e = bh.front();
        bh.removeFront();
        if (e[3] && Ci.find(e[1]) != Ci.find(e[2])) {
            saved += e[0] * remPl;
            wvarln(saved);
            remCi--;
            Ci.unite(e[1], e[2]);
        } else if (!e[3] && Pl.find(e[1]) != Pl.find(e[2])) {
            saved += e[0] * remCi;
            wvarln(saved);
            remPl--;
            Pl.unite(e[1], e[2]);
        }
    }
    writeln(total - saved);
}

void main() {
    stdin.reopen("input.txt", "r");
    auto timer = benchmark!(solve)(1);
    auto resTime = timer[0];
    writeln("\nTime: ", resTime);
}