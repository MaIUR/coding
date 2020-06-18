/*
 * This time, you are supposed to find A+B where A and B are two polynomials.
 *
 * Input Specification:
 * Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:
 * K N1 A1 N2 A2 ... NK AK
 * where K is the number of nonzero terms in the polynomial, Ni and Ai (i=1,2,⋯,K) are the exponents and coefficients, respectively.
 * It is given that 1≤K≤10，0≤NK<...<N2<N1≤1000.
 *
 * Output Specification:
 * For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
 */

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b) {
    return a.first > b.first;
}

int main() {
    int k1, k2;
    while (cin >> k1) {
        unordered_map<int, int> index;
        vector<pair<int, double>> coe;
        int n, count = 0;
        double a;
        for (int i = 0; i < k1; ++i) {
            cin >> n >> a;
            coe.emplace_back(n, a);
            index[n] = coe.size() - 1;
        }
        cin >> k2;
        for (int i = 0; i < k2; ++i) {
            cin >> n >> a;
            if (index.find(n) != index.end()) {
                coe[index[n]].second += a;
                if (coe[index[n]].second == 0)count++;
            } else {
                coe.emplace_back(n, a);
                index[n] = coe.size() - 1;
            }
        }
        cout << coe.size() - count;
        sort(coe.begin(), coe.end(), cmp);
        for (auto &i : coe) {
            if (i.second == 0)continue;
            cout << " " << i.first << " " << fixed << setprecision(1) << i.second;
        }
        cout << endl;
    }
    return 0;
}

//注意相加系数为0的情况，首先要把系数为0的项跳过
//最重要的是在输出个数K的时候，要减去为0的个数