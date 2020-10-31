#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> &d = dungeon;

        //hp[i][j]表示进入房间[i,j]需要的最小健康值，最终结果存储在hp[0][0]中
        vector<vector<int>> hp = vector<vector<int>>(m, vector<int>(n, 0));

        // 先计算进入公主所在的房间所需要的最小血量，如果公主的房间没有恶魔守卫，那进入公主
        // 房间需要的最小健康值就是1，如果有恶魔守卫，那么要满足失去对应的健康值后还剩至少1点
        // 健康值
        hp[m-1][n-1] = d[m-1][n-1] >= 0 ? 1 : (1 - d[m-1][n-1]);

        // 计算表格的最后一行和最后一列的房间的hp，最后一行的房间只能一直向右走到达公主的房间，最后一列则只能一直向下走
        // 以公主的房间为起点反向推导就可以得到对应的hp
        for(int col = n-2; col >= 0; col--) {
            hp[m-1][col] = d[m-1][col] >= hp[m-1][col+1] ? 1 : (hp[m-1][col+1] - d[m-1][col]);
        }
        for(int row = m-2; row >= 0; row--) {
            hp[row][n-1] = d[row][n-1] >= hp[row+1][n-1] ? 1 : (hp[row+1][n-1] - d[row][n-1]);
        }

        // 计算剩余房间的最小血量，剩余的房间都可以向右或向下走，用向右或向下两种走法中的较小值作为最终结果
        // 从右下往左上计算，最终结果存放在[0,0]中
        for(int row = m-2; row >= 0; row--) {
            for(int col = n-2; col >= 0; col--) {
                hp[row][col] = min(
                     d[row][col] > hp[row][col+1] ? 1 : (hp[row][col+1] - d[row][col]),
                     d[row][col] > hp[row+1][col] ? 1 : (hp[row+1][col] - d[row][col])
                );
            }
        }
        
        return hp[0][0];
    }
};
// @lc code=end

