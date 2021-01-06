#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
    void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<int> &used) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
        } else {
            for(int i = 0; i < nums.size(); i++) {
                if(used[i]) {
                    continue;
                }
                temp.push_back(nums[i]);
                used[i] = 1;
                dfs(nums, ans, temp, used);
                temp.pop_back();
                used[i] = 0;
                while(i+1 < nums.size() && nums[i+1] == nums[i]) { i++; }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        dfs(nums, ans, temp, used);
        return ans;
    }
};
// @lc code=end

