#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
    // 122. 买卖股票的最佳时机 II
    int maxProfitNoLimit(vector<int>& prices) {
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

public:
    // 动态规划，hold[i][j]表示第i天交易k次且持有股票的收益，unhold[i][j]表示第i天交易k次且不持有股票的收益，定义卖出操作时交易次数加1
    int maxProfit(int k, vector<int>& prices) {
        const int size = prices.size();
        if(k >= size/2) {
            return maxProfitNoLimit(prices);
        }
        
        vector<vector<int>> hold(size, vector<int>(k+1));
        vector<vector<int>> unhold(size, vector<int>(k+1));

        hold[0][0] = -prices[0];
        unhold[0][0] = 0;

        for(int i = 1; i <= k; i++) {
            hold[0][i] = unhold[0][i] = INT_MIN / 2;
        }

        for(int i = 1; i < size; i++) {
            hold[i][0] = max(hold[i-1][0], unhold[i-1][0] - prices[i]);
            for(int j = 1; j <= k; j++) {
                hold[i][j] = max(hold[i-1][j], unhold[i-1][j] - prices[i]);
                unhold[i][j]  = max(unhold[i-1][j], hold[i-1][j-1] + prices[i]);
            }
        }

        return *max_element(unhold[size-1].begin(), unhold[size-1].end());
    }
};
// @lc code=end

