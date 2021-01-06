#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
    void dfs(vector<int> &c, vector<vector<int>> &ans, int start, vector<int> &temp, int sum, int target) {
        if(target == sum) {
            ans.push_back(temp);
        } else {
            for(int i = start; i < c.size(); i++) {
                if(sum+c[i] > target) {
                    break;
                }
                temp.push_back(c[i]);
                dfs(c, ans, i+1, temp, sum+c[i], target);
                temp.pop_back();
                while(i+1 < c.size() && c[i+1] == c[i]) { i++; } // 从下一个不同的数开始枚举
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(candidates, ans, 0, temp, 0, target);
        return ans;
    }
};
// @lc code=end

