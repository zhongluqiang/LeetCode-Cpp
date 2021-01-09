#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
    void dfs(vector<int> &nums, vector<vector<int>> &ans, int start, vector<int> &temp) {
        ans.push_back(temp);
        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            temp.push_back(nums[i]);
            dfs(nums, ans, i+1, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(nums, ans, 0, temp);
        return ans;
    }
};
// @lc code=end

