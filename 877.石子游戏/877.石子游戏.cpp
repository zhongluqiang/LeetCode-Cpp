#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define INPUT "877.txt"
/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:    
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        
        // dp[i]为计算长度为l的区间时，piles[i]到piles[i+l-1]的分数
        vector<int> dp(piles);
        
        // l=2时，dp[0] = score[0][1], dp[1] = score[1][2], dp[2] = score[2][3]...
        // l=n时，dp[0] = score[0][n-1]
        for(int l = 2; l <= n; l++) {
            for(int i = 0; i < n - l + 1; i++) {
                dp[i] = max(piles[i] - dp[i+1], piles[i+l-1] - dp[i]);
            }
        }
        
        return dp[0] > 0;
    }
};
// @lc code=end

