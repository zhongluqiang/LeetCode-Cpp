#include "leetcode-definition.h"
#define INPUT "856.txt"
/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        stk.push(s[0]);

        for(int i = 1, len = s.size(); i < len; i++) {
            auto ch = s[i];
            if(ch == '(') {
                stk.push(ch);
                continue;
            }
            // 处理')'入栈的情况
            // 计算与当前')'匹配的'('中间的分数，将这个分数压入栈中
            int score = 0;
            if(stk.top() == '(') {
                score = 1; // ()得1分
                stk.pop();
                stk.push(1000); // 这里将基础分数乘以1000，以避免入栈数字与'('的ASCII码(40)冲突的情况，测试用例85就是这种情况
            } else {
                while(stk.top() != '(') {
                    score += stk.top(); // AB得A+B分
                    stk.pop();
                }
                stk.pop();
                stk.push(score * 2); // (A)得2*A分
            }
        }
        
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans/1000;
    }
};
// @lc code=end

