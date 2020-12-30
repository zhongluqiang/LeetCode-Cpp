#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    // 类似22.括号生成，使用子串的结果拼接出当前的结果，f(nums[0~n]) = nums[0] * f(nums[1~n])
    vector<vector<int>> dfs(vector<int> nums) {
        if(nums.size() == 0) {
            return {{}};
        }
        if(nums.size() == 1) {
            return {{nums[0]}};
        } else {
            vector<vector<int>> ans;
            vector<vector<int>> v = dfs(vector<int>(nums.begin()+1, nums.end()));
            ans.push_back({nums[0]});
            for(auto &t : v) {
                ans.push_back(t);
                t.push_back(nums[0]);
                ans.push_back(t);
            }
            return ans;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        auto ans = dfs(nums);
        ans.push_back({}); // 补全空子集，因为空子集不能由子串的结果推导
        return ans;
    }
};
// @lc code=end

