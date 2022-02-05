#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
class Solution {
    int m, n;
    int ans = 0;
    int count = 0;
    const vector<int> dirs{-1, 0, 1, 0, -1};

public:
    void dfs(vector<vector<int>> &grid, int x, int y) {
        count += grid[x][y];
        ans = max(ans, count);

        int cur = grid[x][y];
        grid[x][y] = 0;

        for(int i = 0; i < 4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i+1];
            if(tx < 0 || ty < 0 || tx >= m || ty >= n || !grid[tx][ty]) {
                continue;
            }
            dfs(grid, tx, ty);
        }
        
        grid[x][y] = cur;
        count -= grid[x][y];
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

