#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define INPUT "1335.txt"
/*
 * @lc app=leetcode.cn id=1335 lang=cpp
 *
 * [1335] 工作计划的最低难度
 */

// @lc code=start
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int n = jobDifficulty.size();
        // 总任务数小于天数，说明至少有一天是分配不到任务的
        if(n < d) {
            return -1;
        }
        jobDifficulty.insert(jobDifficulty.begin(), 0);

        // difficulty[i][j]表示一天内完成第i~j个任务的工作难度
        // 其实就是max{jobDifficulty[i]~jobDifficulty[j]}
        vector<vector<int>> difficulty(n+1, vector<int>(n+1, INT_MIN));
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                difficulty[i][j] = max(difficulty[i][j-1], jobDifficulty[j]);
            }
        }

        // dp[i][j]表示第i天完成第j个任务的总难度，最终答案存储在dp[d][n]中
        // dp[i][j] = min{dp[i-1][k] + difficulty[k+1][j]}  k >= i-1 && k < j
        vector<vector<int>> dp(d+1, vector<int>(n+1, INT_MAX/2));
        dp[0][0] = 0;

        for(int i = 1; i <= d; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = i-1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + difficulty[k+1][j]);
                }
            }
        }

        return dp[d][n];
    }
};
// @lc code=end

