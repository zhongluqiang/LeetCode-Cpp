#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "64.txt"
/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
    
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for(int r = rows-1; r >= 0; r--) {
            for(int c = cols-1; c >= 0; c--) {
                if(r == rows-1 && c == cols-1) {
                    dp[r][c] = grid[r][c];
                } else if(r == rows-1) {
                    dp[r][c] = grid[r][c] + dp[r][c+1];
                } else if(c == cols-1) {
                    dp[r][c] = grid[r][c] + dp[r+1][c];
                } else {
                    dp[r][c] = grid[r][c] + min(dp[r][c+1], dp[r+1][c]);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

