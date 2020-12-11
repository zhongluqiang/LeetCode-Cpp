#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "38.txt"
/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
    inline string describe(string s) {
        string ans;
        int pos = 0;
        while(pos < s.size()) {
            auto index = s.find_first_not_of(s[pos], pos);
            if(index == string::npos) {
                ans += to_string(s.size() - pos);
                ans.push_back(s[pos]);
                return ans;
            }
            ans += to_string(index - pos);
            ans.push_back(s[pos]);
            pos += index-pos;
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 2; i <= n; i++) {
            s =  describe(s);
        }
        return s;
    }
};
// @lc code=end

