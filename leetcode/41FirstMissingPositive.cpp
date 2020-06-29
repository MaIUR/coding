//
// Created by lenovo on 2020/6/27.
//

/*
 * Given an unsorted integer array, find the smallest missing positive integer.
 * Your algorithm should run in O(n) time and uses constant extra space.
 */
#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums) {
    int ans = 1;
    bool change = true;
    while (change) {
        change = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == ans) {
                ans++;
                change = true;
            }
        }
        if (!change)break;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == ans) {
                ans++;
                change = true;
            }
        }
    }
    /*for(int i=925;i<1000000;++i){
        cout<<2*i<<", ";
    }*/
    /*for(int i=924;i>=0;--i){
        cout<<2*i-1<<", ";
    }*/
    return ans;
}

int main() {
    /*for (int i = 1092; i < 5000; ++i) {
        cout << 2 * i << ", ";
    }*/
    for (int i = 4991; i >= 1092; --i) {
        cout << 2 * i - 1 << ", ";
    }
}