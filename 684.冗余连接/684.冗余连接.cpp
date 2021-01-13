#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
    class DSU {
        private:
            vector<int> parent;
        public:
            DSU(int n)
            : parent(n) {
                for(int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }
            void merge(int x, int y) {
                parent[find(x)] = find(y); // 设置x的parent为y
            }
            int find(int x) {
                if(x == parent[x]) {
                    return x;
                } else {
                    return find(parent[x]);
                }
            }

    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        DSU dsu(n+1);

        for(const auto &edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if(dsu.find(node1) == dsu.find(node2)) {
                return edge;
            } else {
                dsu.merge(node1, node2);
            }
        }
        return {};
    }
};
// @lc code=end

