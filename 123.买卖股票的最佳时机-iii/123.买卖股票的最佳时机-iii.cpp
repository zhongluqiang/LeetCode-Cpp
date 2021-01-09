#include "leetcode-definition.h"
#include <bits/stdc++.h>
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();
        if(size <= 1) {
            return 0;
        }

        // 动态规划，hold[i][j]表示第i天交易k次手上持有股票的收益，unhold[i][j]表示不持有股票的收益
        vector<vector<int>> hold(size, vector<int>(3));
        vector<vector<int>> unhold(size, vector<int>(3));

        // 初始状态，第1天交易0次
        hold[0][0] = -prices[0];
        unhold[0][0] = 0;

        // 第1天不可能有交易，将交易次数大于0的状态设置成一个较小值
        hold[0][1] = hold[0][2] = INT_MIN/2;
        unhold[0][1] = unhold[0][2] = INT_MIN/2;

        // 遍历剩余天数，推导当天手上持有股票和不持有股票的收益
        for(int i = 1; i < size; i++) {
            // 先计算交易0次的收益
            hold[i][0] = max(hold[i-1][0], unhold[i-1][0] - prices[i]);
            unhold[i][0] = 0;
            // 再推导交易1次和2次的收益
            // 如果第i天持有股票，那么持有的股票可能是在当天买入的，也可能不是当天买入的
            // 如果不是当天买入的，那么收益就是前一天手上持有股票的收益，否则是前一天不持有股票的收益减去当天股票价格
            // 同样，如果第i天不持有股票，也分股票是当天卖出的还是前一天卖出的
            // 如果是当天卖出的，那么收益是前一天持有股票且交易次数减1的收益加上当天股票价格
            // 如果不是当天卖出的，那么收益就是前一天也不持有股票的收益
            hold[i][1] = max(hold[i-1][1], unhold[i-1][1] - prices[i]);
            unhold[i][1] = max(unhold[i-1][1], hold[i-1][0] + prices[i]);

            hold[i][2] = max(hold[i-1][2], unhold[i-1][2] - prices[i]);
            unhold[i][2] = max(unhold[i-1][2], hold[i-1][1] + prices[i]);
        }

        // 返回最后一天所有交易次数对应收益的最大值
        return *max_element(unhold[size-1].begin(), unhold[size-1].end());
    }
};
// @lc code=end

