#include "leetcode-definition.h"

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    // 遇到每个房间只有偷与不偷两种情况，定义robbed[i]表示第i个房间偷的收益累积，unrobbed[i]表示不偷的收益累积，那么有以下转移方程
    // robbed[i] = unrobbed[i-1] + nums[i];              # 偷第i个房间的累积收益等于不偷i-1个房间的收益加上第i个房间的价值
    // unrobbed[i] = max{robbed[i-1], unrobbed[i-1]};    # 不偷第i个房间的累积收益等于第i-1个房间偷与不偷两者的较大值
    // 返回最后一个房间robbed[n-1]与unrobbed[n-1]的较大值就是最终结果
    // todo：只与第i-1个房间有关，降维
    int rob(vector<int>& nums) {
        const int size = nums.size();
        if(size == 0) {
            return 0;
        }

        vector<int> robbed(size);
        robbed[0] = nums[0];
        vector<int> unrobbed(size);
        unrobbed[0] = 0;
        for(int i = 1; i < size; i++) {
            robbed[i] = unrobbed[i-1] + nums[i];
            unrobbed[i] = max(robbed[i-1], unrobbed[i-1]);
        }
        return max(robbed[size-1], unrobbed[size-1]);
    }
};
// @lc code=end

