#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_map<string, function<int(int, int)>> operators = {
            {"+", [](int a, int b)->int { return a+b; }},
            {"-", [](int a, int b)->int { return a-b; }},
            {"*", [](int a, int b)->int { return a*b; }},
            {"/", [](int a, int b)->int { return a/b; }}
        };
        int a, b;
        for(const auto &t : tokens) {
            if(operators.find(t) != operators.end()) {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(operators[t](a, b)); // 注意，这里先出栈b,后出栈a
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
// @lc code=end

