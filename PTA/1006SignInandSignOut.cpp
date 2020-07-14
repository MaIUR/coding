//
// Created by lenovo on 2020/7/13.
//

/*
 * At the beginning of every day, the first person who signs in the computer room will unlock the door, the last one who signs out will lock the door.
 * Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.
 *
 * Input Specification:
 * Each input file contains one test case. Each case contains the records for one day.
 * The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:
 * ID_number Sign_in_time Sign_out_time
 * where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.
 *
 * Output Specification:
 * For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day.
 * The two ID numbers must be separated by one space.
 *
 * Note:
 * It is guaranteed that the records are consistent.
 * That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.
 */

#include <bits/stdc++.h>

using namespace std;

//struct Time {
//    int hour, minute, second;
//
//    Time(int _hour, int _minute, int _second) : hour(_hour), minute(_minute), second(_second) {}
//};

int n, h1, h2, m1, m2, s1, s2, uh = 23, um = 59, us = 59, lh = 0, lm = 0, ls = 0;
string id, unlock, lockup;
//Time early(23, 59, 59), late(0, 0, 0);

bool earlier(int ah, int am, int as, int bh, int bm, int bs) {
    if (ah < bh) return true;
    if (ah > bh) return false;
    if (am < bm) return true;
    if (am > bm) return false;
    return as < bs;
}

bool later(int ah, int am, int as, int bh, int bm, int bs) {
    if (ah > bh) return true;
    if (ah < bh) return false;
    if (am > bm) return true;
    if (am < bm) return false;
    return as > bs;
}

// scanf输入
int main() {
    cin >> n;
    while (n-- > 0) {
        //cout << n << endl;
        //cin >> id >> signin >> signout;
        //cout << id << " " << signin << " " << signout << endl;
        /*h = (signin[0] - '0') * 10 + signin[1] - '0';
        if (h < early.hour) {
            m = (signin[3] - '0') * 10 + signin[4] - '0';
            s = (signin[6] - '0') * 10 + signin[7] - '0';
            early.hour = h;
            early.minute = m;
            early.second = s;
            unlock = id;
        } else if (h == early.hour) {
            m = (signin[3] - '0') * 10 + signin[4] - '0';
            if (m < early.minute) {
                s = (signin[6] - '0') * 10 + signin[7] - '0';
                early.hour = h;
                early.minute = m;
                early.second = s;
                unlock = id;
            } else if (m == early.minute) {
                s = (signin[6] - '0') * 10 + signin[7] - '0';
                if (s < early.second) {
                    early.hour = h;
                    early.minute = m;
                    early.second = s;
                    unlock = id;
                }
            }
        }
        h = (signin[0] - '0') * 10 + signin[1] - '0';
        if (h > late.hour) {
            m = (signin[3] - '0') * 10 + signin[4] - '0';
            s = (signin[6] - '0') * 10 + signin[7] - '0';
            late.hour = h;
            late.minute = m;
            late.second = s;
            lockup = id;
        } else if (h == late.hour) {
            m = (signin[3] - '0') * 10 + signin[4] - '0';
            if (m > late.minute) {
                s = (signin[6] - '0') * 10 + signin[7] - '0';
                late.hour = h;
                late.minute = m;
                late.second = s;
                lockup = id;
            } else if (m == late.minute) {
                s = (signin[6] - '0') * 10 + signin[7] - '0';
                if (s > late.second) {
                    late.hour = h;
                    late.minute = m;
                    late.second = s;
                    lockup = id;
                }
            }
        }*/
        cin >> id;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        //if (earlier(h1, m1, s1, h2, m2, s2)) {
            if (earlier(h1, m1, s1, uh, um, us)) {
                unlock = id;
                uh = h1;
                um = m1;
                us = s1;
            }
            if (later(h2, m2, s2, lh, lm, ls)) {
                lockup = id;
                lh = h2;
                lm = m2;
                ls = s2;
            }
        //}
    }
    cout << unlock << " " << lockup << endl;
    return 0;
}

/*时间的转化可以参考
 int main() {
    int n, minn = INT_MAX, maxn = INT_MIN;
    scanf("%d", &n);
    string unlocked, locked;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int tempIn = h1 * 3600 + m1 * 60 + s1;
        int tempOut = h2 * 3600 + m2 * 60 + s2;
        if (tempIn < minn) {
            minn = tempIn;
            unlocked = t;
        }
        if (tempOut > maxn) {
            maxn = tempOut;
            locked = t;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}
 */
