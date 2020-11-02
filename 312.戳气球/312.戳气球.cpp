#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
using namespace std;
#define INPUT "312.txt"
/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();

        // 首尾填充1，方便计算
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j]表示区间[i,j]的硬币数，最终答案存储在dp[1,n]中
        // dp[i][j] = max{dp[i][k-1] + nums[i-1]*nums[k]*num[j+1] + dp[k+1][j]} i<=k<=j
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        // 枚举所有的区间长度l，遍历所有长度为l的区间[i,j]
        for(int l = 1; l <= n; l++) {
            for(int i = 1; i <= n-l+1; i++) {
                int j = i+l-1;
                for(int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j]);
                }
            }
        }

        return dp[1][n];
    }
};
// @lc code=end

