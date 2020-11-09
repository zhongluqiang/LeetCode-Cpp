#include "leetcode-definition.h"
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define INPUT "934.txt"
/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
    // 邻接矩阵的dfs遍历，x,y是起点位置
    void dfs(vector<vector<int>> &A, int x, int y, queue<pair<int, int>> &q) {
        if(x < 0 || y < 0 || x >= A[0].size() || y >= A[0].size() || A[x][y] != 1) {
            return;
        }
        if(A[x][y] == 2) {
            return;
        }
        A[x][y] = 2;
        q.emplace(x, y);
        dfs(A, x-1, y, q); // 向左dfs
        dfs(A, x, y-1, q); // 向上
        dfs(A, x+1, y, q); // 向右
        dfs(A, x, y+1, q); // 向下
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        // 找第一个小岛的全部坐标点，存储在队列q中
        queue<pair<int, int>> q; 
        bool found = false;
        for(int i = 0; i < A.size() && !found; ++i) {
            for(int j = 0; j < A[0].size() && !found; ++j) {
                if(A[i][j]) {
                    dfs(A, i, j, q);
                    found = true;
                }
            }
        }

        // 此时q中存储了第一个小岛的全部坐标点，并且这些坐标点已经被设置成了2，下一步是对这些坐标点进行广度遍历
        // 把遍历到的结点也加入小岛，即对小岛进行扩展，看扩展到第几步到达另一个小岛
        int steps = 0;
        vector<int> dirs{0, 1, 0, -1, 0};
        while(!q.empty()) {
            size_t size = q.size();
            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int tx = x + dirs[i];
                    int ty = y + dirs[i+1];
                    if(tx < 0 || ty < 0 || tx >= A[0].size() || ty >= A.size() || A[tx][ty] == 2) {
                        continue;
                    }
                    if(A[tx][ty] == 1) {
                        return steps;
                    }
                    A[tx][ty] = 2;
                    q.emplace(tx, ty);
                }
            }
            steps++;
        }
        return -1;
    } // end shortestBridge
};
// @lc code=end

