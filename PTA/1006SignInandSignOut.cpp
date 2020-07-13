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

struct Time {
    int hour, minute, second;

    Time(int _hour, int _minute, int _second) : hour(_hour), minute(_minute), second(_second) {}
};

int n, h, m, s;
string id, signin, signout, unlock, lockup;
Time early(23, 59, 59), late(0, 0, 0);

// scanf输入
int main() {
    cin >> n;
    while (n-- > 0) {
        //cout << n << endl;
        cin >> id >> signin >> signout;
        //cout << id << " " << signin << " " << signout << endl;
        h = (signin[0] - '0') * 10 + signin[1] - '0';
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
        }
    }
    cout << unlock << " " << lockup << endl;
    return 0;
}