#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1489 lang=cpp
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 */

// @lc code=start
class Solution {
    class UnionFind {
    public:
        vector<int> parent; // parent[i] => i的根结点
        vector<int> size;   // size[i] => i所在集合的大小
        int n;              // 节点数
        int setCount;       // 集合数
    public:
        // 初始时每个节点都是一个独立的集合，parent[i] = i, size[i] = 1, setCount = n
        UnionFind(int n) : n(n), setCount(n), parent(n), size(n, 1) {
            // iota(parent.begin(), parent.end(), 0);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        // 返回x所在集合的根结点
        int find(int x) {
            return x == parent[x] ? x : find(parent[x]);
        }
        // 合并x和y，将y的根结点设置成x，并且将y的集合大小增加到x上，同时集合总数减1
        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if(x == y) {
                return false;
            }
            if(size[x] < size[y]) {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
            --setCount;
            return true;
        }
        // 返回x和y是否在同一个集合
        bool connected(int x, int y) {
            return find(x) == find(y);
        }
    };
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            edges[i].push_back(i); // edges[i][3] => 边的编号
        }
        // 将所有边按长度从小到大排序
        sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2){
            return e1[2] < e2[2];
        });
        
        // 计算最小生成树的权值
        UnionFind uf(n);
        int value = 0;
        for(int i = 0; i < m; i++) {
            if(uf.merge(edges[i][0], edges[i][1])) {
                value += edges[i][2];
            }
        }

        // 计算关键边和非关键边
        vector<vector<int>> ans(2);
        for(int i = 0; i < m; i++) {
            // 判断是否关键边
            // 排除第i条边，看剩余边能否构成最小生成树并且权值与原来的相等
            UnionFind uf(n);
            int v = 0;
            for(int j = 0; j < m; j++) {
                if(i != j && uf.merge(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if(uf.setCount != 1 || (uf.setCount== 1 && v > value)) {
                ans[0].push_back(edges[i][3]);
                continue;
            }
            
            // 如果不为关键边，再判断是否伪关键边
            // 先合并第i条边，再用剩余边构成最小生成树，如果权值仍与原来的相等，则这条边就是伪关键边
            uf = UnionFind(n);
            uf.merge(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for(int j = 0; j < m; j++) {
                if(i != j && uf.merge(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if(v == value) {
                ans[1].push_back(edges[i][3]);
            }
        }

        return ans;
    } // end findCriticalAndPseudoCriticalEdges
};
// @lc code=end

