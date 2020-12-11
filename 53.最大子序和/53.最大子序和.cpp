#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "53.txt"
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int size = nums.size();
        
        // cur_max用于记录遍历到当前位置时以当前点为结束点的连续子数组的和
        int cur_max = nums[0];
        // ans记录所有位置的cur_max的最大值
        int ans = cur_max;
        // 遍历后续点， 计算每个点的cur_max，更新ans
        for(int i = 1; i < size; i++) {
            cur_max = max(nums[i], cur_max + nums[i]);
            ans = max(cur_max, ans);
        }
        return ans;
    }
};
// @lc code=end

