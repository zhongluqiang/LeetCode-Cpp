#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    // 动态规划，mincost[i] = min(mincost[i-1], mincost[i-2]) + cost[i]
    int minCostClimbingStairs(vector<int>& cost) {
        cost.insert(cost.begin(), 0);
        cost.push_back(0);

        const int size = cost.size();
        vector<int> mincost(size);
        mincost[0] = cost[0];
        mincost[1] = cost[1];

        for(int i = 2; i < size; i++) {
            mincost[i] = min(mincost[i-1], mincost[i-2]) + cost[i];
        }

        return mincost[size-1];
    }
};
// @lc code=end

