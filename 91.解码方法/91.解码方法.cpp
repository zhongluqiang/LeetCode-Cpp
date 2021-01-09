#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "91.txt"
/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#if 0
class Solution {
    int ans;
    void dfs(const string &s, int start) {
        if(start == s.size()) {
            ans++;
            return;
        }
        // 首字节为0时一定不合法，回溯结束
        if(s[start] == '0') {
            return;
        }
        // 移动1位重新回溯
        dfs(s, start+1);

        // 移动2位重新回溯
        if(start != s.size() - 1) {
            if(s[start] == '1' || (s[start] == '2' && s[start+1] <= '6')) {
                dfs(s, start+2);
            }
        }
    }
public:
    int numDecodings(string s) {
        dfs(s, 0);
        return ans;
    }
};
#else
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') { return 0; }
        vector<int> dp(s.size() + 1);
        dp[0] = dp[1] = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2') {
                    dp[i+1] = dp[i-1];
                } else {
                    return 0;
                }
            } else {
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                    dp[i+1] = dp[i] + dp[i-1];
                } else {
                    dp[i+1] = dp[i];
                }
            }
        }
        return dp.back();
    }
};
#endif
// @lc code=end

