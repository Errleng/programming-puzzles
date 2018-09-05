#include "../library/lib.hpp"
#include <bits/stdc++.h>

#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);
using namespace std;

class FenwickTree {
public:
    size_t N;
    int *BIT;

    FenwickTree(size_t size) {
        this->N = size;
        BIT = new int[N + 1]();
    }

    FenwickTree(int *input, size_t size) {
        this->N = size;
        BIT = new int[N + 1]();
        for (size_t i = 1; i <= N; ++i) {
            update(i, input[i - 1]);
        }
    }

    ~FenwickTree() {
        delete[] BIT;
    }

    void update(size_t pos, int add) {
        while (pos <= N) {
            BIT[pos] += add;
            pos += pos & (-pos);
        }
    }

    int query(int pos) {
        int sum = 0;
        while (pos > 0) {
            sum += BIT[pos];
            pos -= pos & (-pos);
        }
        return sum;
    }

    int getPos(int pos) {
        return query(pos) - query(pos - 1);
    }
};

struct Tree {
    int id, mass;

    Tree() {}

    Tree(int id, int mass) {
        this->id = id;
        this->mass = mass;
    }
};

bool treeCmp(Tree const &t1, Tree const &t2) {
    return t1.mass > t2.mass;
}

struct Query {
    int id, a, b, q;

    Query() {}

    Query(int id, int a, int b, int q) {
        this->id = id;
        this->a = a;
        this->b = b;
        this->q = q;
    }
};

bool queryCmp(Query const &q1, Query const &q2) {
    return q1.q > q2.q;
}

class dmopc14c2p6 {
public:
    void solve(std::istream &in, std::ostream &out) {
        const int MAXN = 1000;
        int N, Q, m, a, b, q;
        int ans[MAXN];
        Tree trees[MAXN];
        Query qs[MAXN];
        in >> N;
//        scanf("%d", &N);
        up(i, N) {
            in >> m;
//            scanf("%d", &m);
            trees[i] = Tree(i + 1, m);
        }
        println("test");

        sort(trees, trees + N, treeCmp);
        FenwickTree BIT(N);
        in >> Q;
//        scanf("%d", &Q);
        up(i, Q) {
            in >> a >> b >> q;
//            scanf("%d", &a);
//            scanf("%d", &b);
//            scanf("%d", &q);
            qs[i] = Query(i, a, b, q);
        }
        sort(qs, qs + Q, queryCmp);

        int ind = 0;
        up(i, Q) {
            while (ind < N && trees[ind].mass >= qs[i].q) {
                BIT.update(trees[ind].id, trees[ind].mass);
                ind++;
            }
            ans[qs[i].id] = BIT.query(qs[i].b + 1) - BIT.query(qs[i].a);
        }
        up(i, Q) {
            out << ans[i] << endl;
        }
    }
};
