#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        const char *p = s.c_str();
        while(*p != '\0' && isspace(*p)) {
            p++;
        }
        if(*p == '\0') {
            return 0;
        }

        bool minus = (*p == '-' ? true : false);
        if(*p == '-' || *p == '+') {
            p++;
        }
        
        int ans = 0;
        while(isdigit(*p)) {
            int x = *p - '0';
            if(ans > (INT_MAX - x) / 10) {
                return INT_MAX;
            }
            if(ans < (INT_MIN + x) / 10) {
                return INT_MIN;
            }
            
            if(minus) {
                ans = ans*10 - x;
            } else {
                ans = ans*10 + x;
            }

            p++;
        }
        
        return ans;
    }
};
// @lc code=end

