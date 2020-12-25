#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
    static inline void appendx(string &dst, const string &s, int x) {
        for(int i = 0; i < x; i++) {
            dst += s;
        }
    }
public:
    string intToRoman(int num) {
        string ans;
        appendx(ans, "M", num/1000); num %= 1000;
        appendx(ans, "CM", num/900); num %= 900;
        appendx(ans, "D", num/500);  num %= 500;
        appendx(ans, "CD", num/400); num %= 400;
        appendx(ans, "C", num/100);  num %= 100;
        appendx(ans, "XC", num/90);  num %= 90;
        appendx(ans, "L", num/50);   num %= 50;
        appendx(ans, "XL", num/40);  num %= 40;
        appendx(ans, "X", num/10);  num %= 10;
        appendx(ans, "IX", num/9); num %= 9;
        appendx(ans, "V", num/5);  num %= 5;
        appendx(ans, "IV", num/4);  num %= 4;
        appendx(ans, "I", num);
        return ans;
    }
};
// @lc code=end

