#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        vector<int> v1, v2;
        int t;
        while(x > 0) {
            t = x%10;
            v1.push_back(t);
            v2.insert(v2.begin(), t);
            x /= 10;
        }
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

