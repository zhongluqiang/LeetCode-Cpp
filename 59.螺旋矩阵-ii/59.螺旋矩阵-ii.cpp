#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
    void fill(vector<vector<int>> &ans, int x1, int y1, int x2, int y2, int start) {
        if(x1 > x2 || y1 > y2) {
            return;
        }
        // 填充矩阵的最外一圈
        for(int y = y1; y <= y2; y++) {
            ans[x1][y] = start++;
        }
        for(int x = x1+1; x <= x2; x++) {
            ans[x][y2] = start++;
        }
        if(x1 != x2) {
            for(int y = y2-1; y >= y1; y--) {
                ans[x2][y] = start++;
            }
        }
        if(y1 != y2) {
            for(int x = x2-1; x >= x1+1; x--) {
                ans[x][y1] = start++;
            }
        }
        // 内圈矩阵递归填充
        fill(ans, x1+1, y1+1, x2-1, y2-1, start);
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        fill(ans, 0, 0, n-1, n-1, 1);
        return ans;
    }
};
// @lc code=end

