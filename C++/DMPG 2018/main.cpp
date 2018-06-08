#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
//cout << ind << " " << type[ind] << " " << zeroCount << " " << nonZCount << endl;
//freopen("input.txt", "r", stdin);
int main() {
    freopen("input.txt", "r", stdin);
    string type;
    cin >> type;
    int ind = type.length()-1;
    int zeroCount = 0;
    int nonZCount = 0;
    int totalZCount = 0;
    bool valid = true;
    while (ind > -1 && valid) {
        if (type[ind] != '0') {
            if (type[ind]-'0' != zeroCount) {
                if (type[ind]-'0' == nonZCount) {
                    nonZCount = 0;
                }
                else {
                    valid = false;
                    break;
                }
            }
            zeroCount = 0;
            ++nonZCount;
            ++totalZCount;
        }
        else {
            ++zeroCount;
        }
        --ind;
    }
    if (totalZCount == 0 && zeroCount > 1) {
        valid = false;
    }
    cout << (valid ? "Valid" : "Invalid") << endl;
    return 0;
}



// B2 main()
//int N, M;
//cin >> N >> M;
//int maxMod = 0;
//if (M <= N) {
//    maxMod = M-1;
//}
//else {
//    maxMod = N;
//}
//cout << N << " " << M << endl;
//cout << (N-1) % M << endl;
//cout << maxMod << endl;

// B1 main()
//double P, C, V;
//int pizzas = 0;
//cin >> P >> C >> V;
//pizzas += ceil(P/3) + ceil(C/3) + ceil(V/3);
//cout << pizzas << endl;
//int N, M, X;
//cin >> N >> M >> X;
//vector<float> numerators, denominators;
//for (int i = 0; i < N; ++i) {
//    float numer;
//    cin >> numer;
//    numerators.push_back(numer);
//}
//for (int i = 0; i < M; i++) {
//    float denom;
//    cin >> denom;
//    denominators.push_back(denom);
//}
//float difference = 1000;
//float closest = -1;
//for (int i = 0; i < denominators.size(); i++) {
//    float gradesSum = 0;
//    float average = 0;
//    for (int j = 0; j < numerators.size(); j++) {
//        gradesSum += numerators[j] / denominators[i];
//    }
//    average = (gradesSum / N) * 100;
//    cout << i << " " << denominators[i] << " " << average << endl;
//    if (average <= 100 && average >= 50) {
//        float diff = abs(X - average);
//        if (diff < difference) {
//            difference = diff;
//            closest = denominators[i];
//        }
//        else if (diff == difference) {
//            if (denominators[i] > closest) {
//                closest = denominators[i];
//            }
//        }
//    }
//}
//if (closest < 0) {
//    cout << "Shinnanigans have failed" << endl;
//}
//else {
//    cout << closest << endl;
//}