#include "leetcode-definition.h"
#define INPUT "121.txt"
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    // 动态规划，第i天的收益 = max{ 前i-1天的收益， 第i天的价格 - 前i-1天的最小价格 }
    // 初始条件：第1天的收益为0
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        int profit = 0;
        int min_prices = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - min_prices);
            min_prices = min(min_prices, prices[i]);
        }

        return profit;
    }
};
// @lc code=end

