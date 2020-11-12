#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1563 lang=cpp
 *
 * [1563] 石子游戏 V
 */

// @lc code=start
class Solution {
    // 求解区间i~j能获取得最大分数
    int dp(int l, int r, vector<int> &sums, vector<vector<int>> &cache) {
        if(l == r) {
            return 0;
        }
        int &ans = cache[l][r];
        if(ans != -1) {
            return ans;
        }
        for(int k = l; k < r; k++) {
            int sum_l = sums[k+1] - sums[l];
            int sum_r = sums[r+1] - sums[k+1];
            if(sum_l > sum_r) {
                ans = max(ans, sum_r + dp(k+1, r, sums, cache));
            } else if(sum_l < sum_r) {
                ans = max(ans, sum_l + dp(l, k, sums, cache));
            } else {
                ans = max(
                    ans, 
                    sum_l + max(dp(l, k, sums, cache), 
                                dp(k+1, r, sums, cache))
                );
            }
        }
        return ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> sums(n+1);
        for(int i = 0; i < n; i++) {
            sums[i+1] = sums[i] + stoneValue[i];
        }

        vector<vector<int>> cache(n, vector<int>(n, -1));
        return dp(0, n-1, sums, cache);
    }
};
// @lc code=end

