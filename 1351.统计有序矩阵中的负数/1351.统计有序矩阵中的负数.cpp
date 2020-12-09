#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int rows = grid.size();
        int ans = 0;

        for(int i = 0; i < rows; i++) {
            for(auto it = grid[i].begin(); it != grid[i].end(); it++) {
                if(*it < 0) {
                    ans += distance(it, grid[i].end());
                    break;
                }
            }
        }
        
        return ans;
    }
};
// @lc code=end

