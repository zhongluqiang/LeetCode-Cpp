#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class Solution {
    class DSU {
        private:
            vector<int> parent;
        public:
            DSU(int n) : parent(n) {
                for(int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }
            void merge(int x, int y) {
                parent[find(x)] = find(y);
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
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        DSU dsu(n);
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int x1 = stones[i][0];
                int y1 = stones[i][1];
                int x2 = stones[j][0];
                int y2 = stones[j][1];
                if(x1 == x2 || y1 == y2) {
                    dsu.merge(i, j);
                }
            }
        }
        int unions = 0;
        for(int i = 0; i < n; i++) {
            if(dsu.find(i) == i) {
                unions++;
            }
        }
        return n - unions;
    }
};
// @lc code=end

