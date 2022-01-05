#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        int prev, next;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '?') {
                continue;
            }

            prev = (i == 0 ? -1 : s[i-1]);
            next = (i == s.size() - 1 ? -1 : s[i+1]);

            //for(int j = 'a'; j <= 'z'; j++) {
            for(int j = 'a'; j <= 'c'; j++) { // 这里没必要从a搜索到z，实际上按题目的设计，最多只会用到a b c其中之一
                if(j != prev && j != next) {
                    s[i] = j;
                    break;
                }
            }
        }
        return s;
    }
};
// @lc code=end

