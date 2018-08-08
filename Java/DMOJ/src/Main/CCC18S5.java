package Main;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class CCC18S5 {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        long total = 0;
        int N, M, P, Q;
        N = in.nextInt();
        M = in.nextInt();
        P = in.nextInt();
        Q = in.nextInt();
        int a, b, c;
        BiEdge[] edges = new BiEdge[P + Q];
        for (int i = 0; i < P; ++i) {
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            total += c * N;
            edges[i] = new BiEdge(a - 1, b - 1, c, false);
        }
        int x, y, z;
        for (int i = 0; i < Q; ++i) {
            x = in.nextInt();
            y = in.nextInt();
            z = in.nextInt();
            total += z * M;
            edges[i + P] = new BiEdge(x - 1, y - 1, z, true);
        }
        Arrays.sort(edges, (u, v) -> u.w - v.w);
        DSet planets = new DSet(N);
        DSet cities = new DSet(M);
        int MSTcost = 0;
        int planetEdges = N;
        int cityEdges = M;
        for (BiEdge e : edges) {
            if (e.t && planets.union(e.u, e.v)) {
                MSTcost += e.w * cityEdges;
                planetEdges--;
            } else if (!e.t && cities.union(e.u, e.v)) {
                MSTcost += e.w * planetEdges;
                cityEdges--;
            }
        }
        out.println(total - MSTcost);
    }
}

class BiEdge {
    int u, v, w;
    boolean t;

    BiEdge(int u, int v, int w, boolean t) {
        this.u = u;
        this.v = v;
        this.w = w;
        this.t = t;
    }
}

class DSet {
    int[] rank, lead;
    int size;

    DSet(int N) {
        size = N;
        rank = new int[N];
        lead = new int[N];
        for (int i = 0; i < N; ++i) {
            lead[i] = i;
        }
    }

    int find(int x) {
        while (x != lead[x]) {
            lead[x] = lead[lead[x]];
            x = lead[x];
        }
        return x;
    }

    boolean union(int a, int b) {
        int xl = find(a);
        int yl = find(b);
        if (xl == yl) {
            return false;
        }
        if (rank[xl] > rank[yl]) {
            lead[yl] = xl;
        } else if (rank[yl] > rank[xl]) {
            lead[xl] = yl;
        } else {
            lead[yl] = xl;
            rank[xl]++;
        }
        return true;
    }
}