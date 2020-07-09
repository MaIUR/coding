//
// Created by lenovo on 2020/7/9.
//
/*
 * Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
 *
 * Input Specification:
 * Each input file contains one test case. Each case occupies one line which contains an N (≤10^100​).
 *
 * Output Specification:
 * For each test case, output in one line the digits of the sum in English words.
 * There must be one space between two consecutive words, but no extra space at the end of a line.
 */
#include <bits/stdc++.h>

using namespace std;
string num;
int sum = 0;
string dict[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
stack<int> s;

int main() {
    while(cin >> num) {
        for (char i : num) {
            sum += i - '0';
        }
        if (sum == 0) {
            cout << "zero" << endl;
            continue;
        }
        while (sum != 0) {
            s.push(sum % 10);
            sum /= 10;
        }
        if (!s.empty()) {
            cout << dict[s.top()];
            s.pop();
        }
        while (!s.empty()) {
            cout << " " << dict[s.top()];
            s.pop();
        }
        cout << endl;
    }
    return 0;
}