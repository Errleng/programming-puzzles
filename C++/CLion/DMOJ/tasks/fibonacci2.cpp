#include "../library/lib.hpp"
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef unsigned long long ull;
typedef unsigned long long matrix[2][2];

class fibonacci2 {
public:
    ull gcd(ull a, ull b) {
        while (true) {
            if (a == 0) return b;
            b %= a;
            if (b == 0) return a;
            a %= b;
        }
    }

    ull lcm(ull a, ull b) {
        ull temp = gcd(a, b);
        return temp ? (a / temp * b) : 0;
    }

    ull get_bit(ull n, ull k) {
        return (n >> k) & 1;
    }


    void copy(matrix *r, const matrix *a) {
        0[*r][0] = 0[*a][0], 0[*r][1] = 0[*a][1];
        1[*r][0] = 1[*a][0], 1[*r][1] = 1[*a][1];
    }

    void multiply(ull m, matrix *p, const matrix *a, const matrix *b) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j) {
                i[*p][j] = 0;
                for (int k = 0; k < 2; ++k)
                    i[*p][j] = (i[*p][j] + i[*a][k] * k[*b][j]) % m;
            }
    }

    void power(ull m, matrix *r, const matrix *a, unsigned long long b) {
        if (b == 1)
            copy(r, a);
        else if (b & 1) {
            matrix even;
            power(m, &even, a, b - 1);
            multiply(m, r, a, &even);
        } else {
            matrix sq;
            multiply(m, &sq, a, a);
            power(m, r, &sq, b >> 1);
        }
    }

    ull fib_mod(ull n, ull m) {
        matrix fib_q = {{1, 1},
                        {1, 0}}, r;
        power(m, &r, &fib_q, n);
        return r[1][0];
    }

    ull fibmod(ull n, ull m) {
        ull f = 0, g = 1, a = 0, b = 1;
        for (int i = 0; i <= (ull) log2(n); ++i) {
            if (get_bit(n, i)) {
                println("get bit", n, i, get_bit(n, i));
                tie(f, g) = make_pair((f * a + g * b) % m, (f * b + g * (a + b)) % m);
            }
            tie(a, b) = make_pair((a * a + b * b) % m, (a * b + b * (a + b)) % m);
            println(f, g, a, b);
        }
        println("DONE");
        return f;
    }

    template<typename ull>
    vector<ull> divisors(ull n) {
        vector<ull> res;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i) {
                    res.pb(i);
                } else {
                    res.pb(i);
                    res.pb(n / i);
                }
            }
        }
        return res;
    }
#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define upto(i, s, e, c) for (int(i) = (s); (i) < (e); (i) += c)
#define up(i, e) upto(i, 0, e, 1)
#define upc(i, e, c) upto(i, 0, e, c)
#define dnto(i, s, e, c) for (int(i) = (s); (i) > (e); (i) -= (c))
#define dn(i, s, e) downto(i, s, e, 1);

using namespace std;

int N;
int nums[101];
vector<int> divisors(vector<pair<int, int>> primes) {
    int divisor_count = 1;
    for (auto p : primes) {
        divisor_count *= p.second;
    }
    vector<int> ans;
    ans.resize(divisor_count);
    int count = 1;
    for (auto p : primes) {
        const int curr_count = count;
        const int prime = p.first;
        const int exponent = p.second;
        int multiplier = 1;
        for (int j = 0; j < exponent; ++j)
        {
            multiplier *= prime;
            for (int i = 0; i < curr_count; ++i)
            {
                ans[count++] = ans[i] * multiplier;
            }
        }
    }
    return ans;
}

vector<int> prime_divisors(vector<pair<int, int>> factors) {
    int divisor_count = 1;
    for (auto p : primes) {
        divisor_count *= 1 + p.second;
    }
    vector<int> ans;
    ans.resize(divisor_count);
    ans[0] = 1;
    int count = 1;
    for (auto p : primes) {
        int curr_count = count;
        int mult = 1;
        for (int j = 0; j < p.second; ++j)
        {
            mult *= p.first;
            for (int i = 0; i < curr_count; ++i)
            {
                ans[count++] = ans[i] * mult;
            }
        }
    }
    return ans;
}

vector<pair<int, int>> prime_factorize(int n) {
    vector<pair<int, int>> res;
    map<int, int> exp;
    while (n % 2 == 0) {
        auto it = exp.find(2);
        if (it != exp.end()) {
            it->second++;
        } else {
            exp.insert({2, 1});
        }
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            auto it = exp.find(i);
            if (it != exp.end()) {
                it->second++;
            } else {
                exp.insert({i, 1});
            }
            n = n / i;
        }
    }
    if (n > 2) {
        auto it = exp.find(n);
        if (it != exp.end()) {
            it->second++;
        } else {
            exp.insert({n, 1});
        }
    }
    for (auto it = exp.begin(); it != exp.end(); ++it) {
        res.push_back(pair<int, int>(it->first, it->second));
    }
    return res;
}

int gcf(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcf(b, a % b);
}

int main()
{
    scan(N);
    up (i, N) {
        scan(nums[i]);
    }
    int hcf = 0;
    upto(i, 1, N, 1) {
        hcf = gcf(abs(nums[i] - nums[i-1]), hcf);
    }
    for (int i = 2; i <= hcf / 2; ++i) {
        if (hcf % i == 0) {
            printf("%d ", i);
        }
    }
    printf("%d\n", hcf);
    cout << hcf << endl;
    auto pf = prime_factorize(hcf);
    for (auto i : pf) {
        cout << i.first << " " << i.second << endl;
    }
    auto dv = divisors(pf);
    for (auto i : divisors) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

    template<typename ull>
    vector<pair<ull, ull>> prime_factorize(ull n) {
        vector<pair<ull, ull>> res;
        map<int, int> exp;
        while (n % 2 == 0) {
            auto it = exp.find(2);
            if (it != exp.end()) {
                it->se++;
            } else {
                exp.insert({2, 1});
            }
            n = n / 2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2) {
            while (n % i == 0) {
                auto it = exp.find(i);
                if (it != exp.end()) {
                    it->se++;
                } else {
                    exp.insert({i, 1});
                }
                n = n / i;
            }
        }
        if (n > 2) {
            auto it = exp.find(n);
            if (it != exp.end()) {
                it->se++;
            } else {
                exp.insert({n, 1});
            }
        }
        for (auto it = exp.begin(); it != exp.end(); ++it) {
            res.push_back(pair<ull, ull>(it->fi, it->se));
        }
        return res;
    }

    template<typename ull>
    ull prime_power_divisor(ull p, ull k) {
        if (k == 0)
            return 1;
        else if (p == 5)
            return (5 * static_cast<ull>(pow(p, k - 1)));
        int e = (p % 5 == 2 || p % 5 == 3) ? 1 : -1;
        ull res = 0;
        for (auto i : divisors(p + e)) {
            if (fib_mod(i, p) == 0) {
                res = i * static_cast<ull>(pow(p, k - 1));
                break;
            }
        }
        return res;
    }

    template<typename ull>
    ull get_pisano_period(ull m) {
        ull a = 0, b = 1, c = a + b;
        for (int i = 0; i < m * m; i++) {
            c = (a + b) % m;
            a = b;
            b = c;
            if (a == 0 && b == 1) return i + 1;
        }
    }

    template<typename ull>
    ull pisano_period(ull n) {
        if (n <= 0)
            return 0;
        else if (n == 1)
            return 1;
        stringstream error;
        error << "CONJECTURE DISPROVED! For n = " << n;
        ull d = 1;
        auto pf = prime_factorize(n);
        for (auto i : pf) {
            d = lcm(d, prime_power_divisor(i.fi, i.se));
//            println(prime_power_divisor(i.fi, i.se));
        }
        for (int i = 0; i < 3; ++i) {
            ull t = d << i;
            if (fib_mod(t, n) == 0 && fib_mod(t + 1, n) == 1) {
                return t;
            }
        }
        throw runtime_error(error.str());
        return -1;
    }

    template<typename F, typename... Args>
    double funcTime(F func, Args &&... args) {
        auto t1 = std::chrono::high_resolution_clock::now();
        func(std::forward<Args>(args)...);
        auto t2 = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    }

    void factorize(long long n) {
        int count = 0;

        // count the number of times 2 divides
        while (!(n % 2)) {
            n >>= 1; // equivalent to n=n/2;
            count++;
        }

        // if 2 divides it
        if (count)
            cout << "(" << 2 << "," << count << ") ";

        // check for all the possible numbers that can
        // divide it
        for (long long i = 3; i <= sqrt(n); i += 2) {
            count = 0;
            while (n % i == 0) {
                count++;
                n = n / i;
            }
            if (count)
                cout << "(" << i << "," << count << ") ";
        }

        // if n at the end is a prime number.
        if (n > 2)
            cout << "(" << n << "," << count + 1 << ") ";
        cout << endl;
    }

    void solve(std::istream &in, std::ostream &out) {
        const ull M = static_cast<ull>(pow(10, 9)) + 7;
        ull N;
        in >> N;
        out << fib_mod(N, M) << " " << pisano_period(M) << endl;

//        const ull large = pow(11, 4);

//        println("Large:", large);
//
//        auto t1 = std::chrono::high_resolution_clock::now();
//        factorize(large);
//        auto t2 = std::chrono::high_resolution_clock::now();
//        println("ms:", std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());
//
//        t1 = std::chrono::high_resolution_clock::now();
//        auto pf = prime_factorize(large);
//        for (auto i : pf) {
//            cout << "(" << i.fi << "," << i.se << ")" << " ";
//        }
//        cout << endl;
//        t2 = std::chrono::high_resolution_clock::now();
//        println("ms:", std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());

        const int LIMIT = 11;
        for (int i = 2; i <= LIMIT; ++i) {
            for (int j = 2; j <= LIMIT; ++j) {
                ull test = pow(i, j);
                // cout << pisano_period(test) << " ";
            }
        }
        cout << endl;
        auto d = 41841412812;
        auto n = 31381059609;
        for (int i = 0; i < 3; ++i) {
            auto t = d << i;
            auto a = fibmod(t, n);
            auto b = fibmod(t + 1, n);
            cout << t << ": " << a << " " << b << endl;
        }
        std::bitset<64> x(n);
        cout << x << endl;
        auto l = n;
        l = 0;
        cout << get_bit(n, l) << endl;
    }
};
