//
// Created by lenovo on 2020/7/10.
//

/*
 * A number that will be the same when it is written forwards or backwards is known as a Palindromic Number.
 * For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
 * Non-palindromic numbers can be paired with palindromic ones via a series of operations.
 * First, the non-palindromic number is reversed and the result is added to the original number.
 * If the result is not a palindromic number, this is repeated until it gives a palindromic number.
 * For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.
 * Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.
 *
 * Input Specification:
 * Each input file contains one test case.
 * Each case consists of two positive numbers N and K, where N (≤10^10​​) is the initial numer and K (≤100) is the maximum number of steps.
 * The numbers are separated by a space.
 *
 * Output Specification:
 * For each test case, output two numbers, one in each line.
 * The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number.
 * If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.
 */

#include <bits/stdc++.h>

using namespace std;

int k, c = 0;
string n;

bool isPalindromic(string num) {
    int l = 0, r = num.length() - 1;
    while (l < r) {
        if (num[l] != num[r]) return false;
        l++;
        r--;
    }
    return true;
}

string add(const string &s) {
    int i = 0, j = s.length() - 1, carry = 0, sum;
    string ans;
    while (j >= 0) {
        sum = s[i] + s[j] - '0' * 2 + carry;
        carry = sum / 10;
        ans = to_string(sum % 10) + ans;
        j--;
        i++;
    }
    if (carry != 0)ans = to_string(carry) + ans;
    return ans;
}

int main() {
    while (cin >> n >> k) {
        c = 0;
        while (!isPalindromic(n)) {
            if (c == k) break;
            n = add(n);
            c++;
        }
        cout << n << endl << c << endl;
    }
    return 0;
}