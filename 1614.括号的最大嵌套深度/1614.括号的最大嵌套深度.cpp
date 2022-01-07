#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int tmp = 0;
        stack<int> stk;
        for(auto ch : s) {
            if(ch == '(') {
                // stk.push(ch);
                // ans = max(ans, (int)stk.size());
                tmp++;
                ans = max(ans, tmp);
            } else if(ch == ')') {
                // stk.pop();
                tmp--;
            }
        }
        return ans;
    }
};
// @lc code=end

