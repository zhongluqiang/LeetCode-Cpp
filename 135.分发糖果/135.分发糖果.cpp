#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int size = ratings.size();
        vector<int> candies(size, 1); // 初始时每人1一颗糖

        // 从前往后比较，看有没有少发
        for(int i = 1; i < size; i++) {
            if(ratings[i] > ratings[i-1]) {
                if(candies[i] <= candies[i-1]) {
                    candies[i] = candies[i-1] + 1;
                }
            }
        }

        // 从后往前比较，看有没有少发
        for(int i = size-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                if(candies[i] <= candies[i+1]) {
                    candies[i] = candies[i+1] + 1;
                }
            }
        }

        // 求和，返回最终结果
        int ans = 0;
        for(auto i : candies) {
            ans += i;
        }
        return ans;
    }
};
// @lc code=end

