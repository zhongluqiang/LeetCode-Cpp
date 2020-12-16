#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty()) {
            return 0;
        }
        long long ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans = ans*26 + s[i]- 'A' + 1;
        }
        return static_cast<int>(ans);
    }
};
// @lc code=end

