#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<int> &temp, int n, int k, int x) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for(int i = x+1; i <= n; i++) {
            temp.push_back(i);
            dfs(temp, n, k, i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(temp, n, k, 0);
        return ans;
    }
};
// @lc code=end

