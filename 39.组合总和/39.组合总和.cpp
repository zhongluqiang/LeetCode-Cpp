#include "leetcode-definition.h"
#define INPUT "39.txt"
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    void dfs(vector<int> &c, vector<vector<int>> &ans, int start, vector<int> &temp, int target) {
        if(target < 0) { 
            return;
        }
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = start; i < c.size(); i++) {
            if(c[i] > target) {
                continue; // 这里不能直接break，因为在不排序的情况下，后面可能还有符合的c[i]，如果是已经排序的，那么可以直接break
            }
            temp.push_back(c[i]);
            dfs(c, ans, i, temp, target-c[i]);
            temp.pop_back();
        }
    }

    void dfs2(vector<int> &c, vector<vector<int>> &ans, int start, vector<int> &temp, int sum, int target) {
        if(target == sum) {
            ans.push_back(temp);
        } else {
            for(int i = start; i < c.size(); i++) {
                if(sum+c[i] <= target) {
                    temp.push_back(c[i]);
                    dfs2(c, ans, i, temp, sum+c[i], target);
                    temp.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        //sort(candidates.begin(), candidates.end());
        dfs(candidates, ans, 0, temp, target);
        //dfs2(candidates, ans, 0, temp, 0, target);
        return ans;
    }
};
// @lc code=end

