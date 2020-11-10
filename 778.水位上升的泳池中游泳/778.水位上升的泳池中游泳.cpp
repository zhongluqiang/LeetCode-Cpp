#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */

// @lc code=start
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();

        // 优先队列，存储time的最小值时和其坐标点的位置，坐标转化成一维的
        priority_queue<pair<int, int>> q;  // -time, y*N+x
        q.push({-grid[0][0], 0*n+0});
        
        vector<int> seen(n*n);
        vector<int> dirs{-1, 0, 1, 0, -1};
        seen[0*n+0] = 1;
        while(!q.empty()) {
            auto node = q.top(); q.pop();
            int t = -node.first;
            int x = node.second % n;
            int y = node.second / n;
            if(x == n-1 && y == n-1) {
                return t;
            }
            // 广度遍历，向四个方向扩展，计算邻结点的total cost
            for(int i = 0; i < 4; i++) {
                int tx = x + dirs[i];
                int ty = y + dirs[i+1];
                if(tx < 0 || ty < 0 || tx >= n || ty >= n) {
                    continue;
                }
                if(seen[tx*n + ty]) {
                    continue;
                }
                seen[tx*n + ty] = 1;
                q.push({-max(t, grid[ty][tx]), ty*n + tx});
            }
        }
        return -1;
    }
};
// @lc code=end

