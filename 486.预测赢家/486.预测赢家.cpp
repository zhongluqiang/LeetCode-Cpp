#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
using namespace std;
#define INPUT "486.txt"
/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int n = nums.size();

        // dp[i]是计算长度为l时区间[i, i+l-1]的分数，最后结果存储在dp[0]中，表示长度为n时，区间[0, n-1]的分数
        vector<int> dp(nums);
        for(int l = 2; l <= n; l++) {
            for(int i = 0; i < n-l+1; i++) {
                dp[i] = max(nums[i] - dp[i+1], nums[i+l-1] - dp[i]);
            }
        }
        return dp[0] >= 0;
    }
};
// @lc code=end

