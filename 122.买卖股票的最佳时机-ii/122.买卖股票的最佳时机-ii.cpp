#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        vector<int> profit;
        for(int i = 1; i < prices.size(); i++) {
            profit.push_back(prices[i] - prices[i-1]);
        }

        int ans  = 0;
        for(auto i : profit) {
            if(i > 0) {
                ans += i;
            }
        }
        return ans;
    }
};
// @lc code=end

