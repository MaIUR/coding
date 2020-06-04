//
// Created by lenovo on 2020/6/4.
//

/* Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by
 * commas (unless there are less than four digits).
 *
 * Input Specification:
 * Each input file contains one test case. Each case contains a pair of integers a and b where −10^6≤a,b≤10^6.
 * The numbers are separated by a space.
 *
 * Output Specification:
 * For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b) {
        a = a + b;
        if (a < 0) {
            cout << "-";
            a = a * (-1);
        }
        b = 0;
        string ans = "";
        if (a == 0)cout << 0 << endl;
        else {
            while (a != 0) {
                ans = to_string(a % 10) + ans;
                a /= 10;
                b++;
                if (b == 3 && a != 0) {
                    ans = "," + ans;
                    b = 0;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}