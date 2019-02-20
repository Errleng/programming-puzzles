#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MAXR 1001

using namespace std;

int N;
unordered_map<int, int> freq;

int main() {
    int maxFreq = -1, secondMaxFreq = -1;
    vector<int> firsts, seconds;

    cin >> N;

    for (int i=1; i<=N; ++i) {
        int a;
        cin >> a;
        ++freq[a];
    }

    for (auto const &it : freq) {
        int i = it.first;
        int f = it.second;
        if (f > 0) {
            if (f > maxFreq) {
                secondMaxFreq = maxFreq;
                maxFreq = f;
                seconds = firsts;
                firsts.clear();
                firsts.push_back(i);
            } else if (f == maxFreq) {
                firsts.push_back(i);
            } else if (f > secondMaxFreq) {
                secondMaxFreq = f;
                seconds.push_back(i);
            } else if (f == secondMaxFreq) {
                seconds.push_back(i);
            }
        }
    }

    int diff = -1;
    if (firsts.size() > 1) {
        int minE = 1001;
        int maxE = -1;
        for (int r : firsts) {
            if (r > maxE) {
                maxE = r;
            }
            if (r < minE) {
                minE = r;
            }
        }
        diff = abs(maxE - minE);
    } else if (seconds.size() > 1) {
        for (int r: seconds) {
            diff = max(diff, abs(firsts[0] - r));
        }
    } else {
        diff = abs(firsts[0] - seconds[0]);
    }
    cout << diff << '\n';
    return 0;
}