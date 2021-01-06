#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#if 0
// 标准库版
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};
#else
// 回溯版
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
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        dfs(nums, ans, temp, used);
        return ans;
    }
};
#endif
// @lc code=end

