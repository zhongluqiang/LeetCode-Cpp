#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int size = prices.size();
        int buy = prices[0] + fee;
        int profit = 0;
        for(int i = 1; i < size; i++) {
            if(prices[i] + fee < buy) {
                buy = prices[i] + fee;
            } else if(prices[i] > buy) {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};
// @lc code=end

