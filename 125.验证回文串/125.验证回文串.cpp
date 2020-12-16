#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(auto ch : s) {
            if(isalnum(ch)) {
                s1.push_back(tolower(ch));
            }
        }
        if(s1.empty()) {
            return true;
        }
        
        string s2(s1.rbegin(), s1.rend());
        return s1 == s2;
    }
};
// @lc code=end

