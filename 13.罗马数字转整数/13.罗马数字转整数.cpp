#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "13.txt"
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
    // 所有合法的罗马数字字符
    unordered_map<string, int> maps = {
        {"I", 1},
        {"IV", 4},
        {"IX", 9},
        {"V", 5},
        {"X", 10},
        {"XL", 40},
        {"XC", 90},
        {"L", 50},
        {"C", 100},
        {"CD", 400},
        {"CM", 900},
        {"D", 500},
        {"M", 1000}
    };
public:
    int romanToInt(string s) {
        int ans = 0;
        int i = 0;
        string s1, s2;
        while(i < s.size()) {
            s1 = s.substr(i, 1);
            s2 = s.substr(i, 2);
            // 题目保证输入合法，所以这里if和else必中一个
            if(maps.find(s2) != maps.end()) {
                ans += maps[s2];
                i += 2;
            } else {
                ans += maps[s1];
                i += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

