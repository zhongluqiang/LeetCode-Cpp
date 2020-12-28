#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "22.txt"
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#if 0
class Solution {
    vector<vector<string>> ans; // ans[i]表示生成i对括号的组合

    void generate(int n) {
        if(n == 0) { return ; }
        if(n == 1) { ans[1] = {"()"}; return; }
        
        // 枚举子组合，用小于n的已知结果来拼接出n的结果
        set<string> answer;
        for(int i = 1; i <= n-1; i++) {
            auto &v1 = ans[i];
            auto &v2 = ans[n-i];
            for(auto &s1 : v1) {
                for(auto &s2 : v2) {
                    answer.insert(s1+s2);
                }
            }
        }
        // 新括号加在最左和最右的情况无法由子结果拼接出来，这里要额外添加
        auto &v = ans[n-1];
        for(auto &s : v) {
            answer.insert("("+s+")");
        }
        ans[n].resize(answer.size());
        copy(answer.begin(), answer.end(), ans[n].begin());
        return;
    }
public:
    // 动态规划，n的结果可以由小于n的结果推导
    vector<string> generateParenthesis(int n) {
        ans.resize(n+1);
        for(int i = 1; i <= n; i++) {
            generate(i);
        }
        return ans[n];
    }
};
#else
class Solution {
    // 深度优先搜索，left,right表示剩余可用的左、右括号数
    void dfs(int left, int right, string cur, vector<string> &ans) {
        // 剩余的左括号大于右括号，说明之前用掉的右括号比左括号多，例如())，一旦出现这种情况当前组合就是无效的，可以直接返回
        if(left > right) {
            return;
        }
        // 左右括号都用完了，将结果加入结果集合
        if(left == 0 && right == 0) {
            ans.push_back(cur);
        }
        // 还有左右括号没用完，继续递归
        if(left > 0) {
            dfs(left-1, right, cur+"(", ans);
        }
        if(right > 0) {
            dfs(left, right-1, cur+")", ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0) { return ans; }
        if(n == 1) { return {"()"}; }

        dfs(n, n, "", ans);
        return ans;
    }
};
#endif
// @lc code=end

