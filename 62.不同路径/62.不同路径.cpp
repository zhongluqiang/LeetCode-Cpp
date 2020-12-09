#include <bits/stdc++.h>
using namespace std;
#define INPUT "62.txt"
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // 动态规划解法，转移方程：dp[i][j] = dp[i+1][j] + dp[i][j+1]
    // 说明：从当前位置只能向下或向右走，那当前位置的走法就是下面位置的走法加上右边位置的走法
    // 从终点向起点反推，终点以及最后一行和最后一列只有一种走法，dp值为1
    int uniquePaths(int m, int n) { // m列 n行
        vector<vector<int>> dp(n, vector<int>(m, 0));

        //最后一行和最后一列只有一种走法
        for(int i = 0; i < n; i++) {
            dp[i][m-1] = 1;
        }
        for(int i = 0; i < m; i++) {
            dp[n-1][i] = 1;
        }

        // dp[i][j] = dp[i+1][j] + dp[i][j+1]
        for(int i = n-2; i >= 0; i--) {
            for(int j = m-2; j >= 0; j--) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    } // end uniquePaths
};
// @lc code=end

