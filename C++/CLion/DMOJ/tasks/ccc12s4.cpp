#include "../library/lib.hpp"
#include <bits/stdc++.h>

using namespace std;

int N;

struct State {
    int cont[8];
    int d;

    State(int dist) {
        memset(cont, 0, sizeof(cont));
        d = dist;
    }

    void print() {
        cout << "(";
        cout << cont[0];
        for (int i = 1; i < 7; ++i) {
            cout << ", " << cont[i];
        }
        cout << ")" << endl;
    }

    void set(int a, int b) {
        cont[a] |= 1 << b;
    }

    int get(int a, int b) {
        return cont[a] & (1 << b);
    }

    string to_state() {
        stringstream ss;
        for (int i = 0; i < N - 1; ++i) {
            ss << cont[i] << '/';
        }
        ss << cont[N - 1];
        return ss.str();
    }

    string to_state_correct() {
        stringstream ss;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (this->get(i, j)) {
                    ss << j;
                }
            }
            ss << " ";
        }
        return ss.str();
    }
};

class ccc12s4 {
public:
    int last_bit(int N) {
        if (N == 0)
            return -1;
        return N & (-N);
    }

    void solve(std::istream &in, std::ostream &out) {
        const int MAXN = 8;
        const unsigned long long LIMIT = 1 << 24;

        int coins[MAXN];
        int stack[MAXN];
        int8_t *moves = new int8_t[LIMIT];

        queue<int> q;

        int temp;

        in >> N;
        while (N != 0) {
            memset(coins, 0, sizeof(coins));
            fill(moves, moves + LIMIT, SCHAR_MAX);
            q = {};

            for (int i = 0; i < N; ++i) {
                in >> temp;
                coins[temp - 1] = i;
            }
            int start, end;
            start = end = 0;
            for (int i = 0; i < N; ++i) {
                start |= coins[i] << (3 * i);
                end |= i << (3 * i);
                println(start, end);
            }
            moves[start] = 0;
            q.push(start);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                fill(stack, stack + N, INT_MAX);
                for (int i = N - 1; i >= 0; i--) {
                    stack[(cur >> (3 * i)) % 8] = i;
                }
                for (int i = 0; i < N - 1; i++) {
                    if (stack[i] < stack[i + 1]) {
                        int next = cur & ~(7 << (3 * stack[i])) | (i + 1) << (3 * stack[i]);
                        if (moves[cur] + 1 < moves[next]) {
                            moves[next] = static_cast<int8_t>(moves[cur] + 1);
                            q.push(next);
                        }
                    } else if (stack[i + 1] < stack[i]) {
                        int next = cur & ~(7 << (3 * stack[i + 1])) | (i) << (3 * stack[i + 1]);
                        if (moves[cur] + 1 < moves[next]) {
                            moves[next] = static_cast<int8_t>(moves[cur] + 1);
                            q.push(next);
                        }
                    }
                }
            }
            if (moves[end] == SCHAR_MAX)
                out << "IMPOSSIBLE" << endl;
            else
                out << static_cast<int>(moves[end]) << endl;
            println();
            in >> N;
        }



//        const int MAXN = 8;
//        set<string> vis;
//        set<string> correct;
//        queue<State> q;
//        int input;
//        in >> N;
//        while (N != 0) {
//            q = {};
//            vis.clear();
//            correct.clear();
//            State start(0);
//            for (int i = 0; i < N; ++i) {
//                in >> input;
//                start.set(i, input - 1);
//            }
//
////            start.print();
//
//            bool possible = false;
//            q.push(start);
//            while (!q.empty()) {
//                State curr = q.front();
//                q.pop();
//                string state = curr.to_state_correct();
//
////                string correct_state = curr.to_state_correct();
////                if (correct.find(correct_state) == correct.end())
////                    correct.insert(correct_state);
////                else
////                    continue;
//
//                if (vis.find(state) != vis.end())
//                    continue;
//
////                println(state);
//
//                vis.insert(state);
//
//                bool flag = true;
//                for (int i = 0; flag && i < N; ++i) {
//                    if (!curr.get(i, i)) {
//                        flag = false;
//                    }
//                }
//                if (flag) {
//                    out << curr.d << endl;
//                    possible = true;
//                    break;
//                }
//
////                curr.print();
//
//                for (int i = 0; i < N; ++i) {
//                    for (int j = 0; j < N; ++j) {
//                        if (i == j || abs(i - j) > 1 || curr.cont[i] == 0)
//                            continue;
//                        int topI = last_bit(curr.cont[i]);
//                        int topJ = last_bit(curr.cont[j]);
//                        if (topJ != -1 && topJ < topI)
//                            continue;
//                        State next(curr.d + 1);
//                        for (int k = 0; k < N; ++k) {
//                            next.cont[k] = curr.cont[k];
//                        }
//                        next.cont[j] |= topI;
//                        next.cont[i] &= (~topI);
//
////                        print(last1, last2);
////                        next.print();
//
//                        q.push(next);
//                    }
//                }
//            }
////            for (auto i : vis) {
////                println(i);
////            }
////            for (auto i : correct) {
////                println(i);
////            }
//            if (!possible)
//                out << "IMPOSSIBLE" << endl;
////            println("There are", vis.size(), "states, and the correct number is", correct.size());
////            if (vis.size() != correct.size()) {
////                out << "WRONG SIZES!" << endl;
////            }
//            in >> N;
//        }
    }
};
