#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int rows = obstacleGrid.size();
        const int cols = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[rows-1][cols-1]) {
            return 0;
        }

        vector<vector<long>> dp(rows, vector<long>(cols, 0));

        //最后一列和最后一行只有一种走法，如果有障碍物，障碍物及后面的格子走法都是0
        bool trapped = false;
        for(int i = rows-1; i >= 0; i--) {
            if(trapped) {
                dp[i][cols-1] = 0;
                continue;
            }
            if(obstacleGrid[i][cols-1]) {
                trapped = true;
                dp[i][cols-1] = 0;
            } else {
                dp[i][cols-1] = 1;
            }
        }
        trapped = false;
        for(int i = cols-1; i >= 0; i--) {
            if(trapped) {
                dp[rows-1][i] = 0;
                continue;
            }
            if(obstacleGrid[rows-1][i]) {
                trapped = true;
                dp[rows-1][i] = 0;
            } else {
                dp[rows-1][i] = 1;
            }
        }

        // dp[i][j] = dp[i+1][j] + dp[i][j+1]
        for(int i = rows-2; i >= 0; i--) {
            for(int j = cols-2; j >= 0; j--) {
                if(obstacleGrid[i][j]) {
                    continue;
                }
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

