#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
class Solution {
    class DSU{
        private:
            // parent[i]表示i节点所在集合的祖先结点，sz[i]表示以i为集合祖先、也就是parent[i]=i时，这个集合的节点数量
            vector<int> parent, sz; 
        public:
            DSU(int n) : parent(n), sz(n) {
                for(int i = 0; i < n; i++) {
                    // 初始时每个节点都是一个集合
                    parent[i] = i;
                    sz[i] = 1;
                }
            }
            // 合并x和y，将x加入y所在的集合，同时，将原本属于x集合的节点数量增加到y集合的节点数量
            // 如果x和y本来就在同一个集合，那什么也不做
            void merge(int x, int y) {
                int parentx = find(x);
                int parenty = find(y);
                if(parentx == parenty) {
                    return;
                } else {
                    parent[parentx] = parenty;
                    sz[parenty] += sz[parentx];
                }
            }
            int find(int x) {
                return x == parent[x] ? x : find(parent[x]);
            }
            // 获取x所在集合的节点数
            int count(int x) {
                return sz[find(x)];
            }
    };
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int h = grid.size(), w = grid[0].size();
        DSU dsu(h*w + 1);
        vector<vector<int>> status = grid;
        
        // 反向考虑问题，先将所有待敲掉的砖全敲掉，得出敲掉之后的并查集合，再从后向前依次补上敲掉的砖块，每补一块，
        // 计算补上之后根节点的并查集多了几个节点，就是这次操作会掉落的砖块数量

        // 先敲掉所有砖块，记录状态信息status
        for(int i = 0; i < hits.size(); i++) {
            status[hits[i][0]][hits[i][1]] = 0;
        }

        // 构造status的并查集合
        // 注意将第一行的全部节点看成一个集合，为方便计算将h*w设置成根结点，后续要根据这个集合的节点数量来计算掉落的砖块数
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(status[i][j]) {
                    if(i == 0) {
                        // 顶行的点特殊处理，将h*w设置成父节点
                        dsu.merge(i*w + j, h*w); // 坐标归一化处理，(i,j)转化成i*w+j
                    } 
                    // 只需要合并左边和上边的节点也能遍历完所有相邻节点，不需要检查四个方向
                    if(i > 0 && status[i-1][j]) {
                        dsu.merge(i*w + j, (i-1)*w + j);
                    }
                    if(j > 0 && status[i][j-1]) {
                        dsu.merge(i*w + j, i*w + j-1);
                    }
                }
            }
        }

        // 从后往前补上被敲掉的砖块，计算补上之后以h*w为父节点的集合数量增加了多少，作为最终答案
        const int dirs[] = {-1, 0, 1, 0, -1};
        vector<int> ans(hits.size(), 0);
        for(int i = hits.size()-1; i >= 0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];
            if(grid[x][y] == 0) {
                // 被敲掉的位置本来就没有砖块，那这次的结果一定是0
                ans[i] = 0;
                continue;
            }
            int prev_size = dsu.count(h*w); // 没补之前顶行集合的节点数
            
            if(x == 0) {
                // 补顶行的砖，先将这个点合并到顶行的集合
                dsu.merge(y, h*w);
            }
            // 遍历周围4个相邻的点，将(x,y)依次合并到这4个点的集合，最后看根结点所在的集合增加了几个元素
            for(int i = 0; i < 4; i++) {
                int tx = x + dirs[i];
                int ty = y + dirs[i+1];
                if(tx < 0 || ty < 0 || tx >= h || ty >= w) {
                    continue;
                }
                if(status[tx][ty] == 1) {
                    // dsu.merge(tx*w+ty, x*w+y);
                    dsu.merge(x*w+y, tx*w+ty); // 将当前节点(x,y)加入到周围4个节点的集合，注意这里不要搞反了，(x,y)是新来的
                }
            }
            int cur_size = dsu.count(h*w); // 补上之后顶行集合的节点数
            ans[i] = max(0, cur_size - prev_size - 1);
            status[x][y] = 1; // 还原补上之后的状态
        }
        return ans;
    }
};
// @lc code=end

