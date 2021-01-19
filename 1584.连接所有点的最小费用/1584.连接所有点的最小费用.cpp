#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
class Solution {
    class DSU {
        private:
            vector<int> f, rank;
        public:
            DSU(int n) : f(n), rank(n, 1) {
                for(int i = 0; i < n; i++) {
                    f[i] = i;
                }
            }
            int find(int x) {
                return x == f[x] ? x : find(f[x]);
            }
            int merge(int x, int y) {
                int fx = find(x), fy = find(y);
                if(fx == fy) {
                    return false;
                }
                if(rank[fx] < rank[fy]) {
                    // 保证fx的权值较大
                    swap(fx, fy);
                }
                rank[fx] += rank[fy];
                f[fy] = fx;
                return true;
            }
    };
    struct Edge {
        int len, x, y;
        Edge(int len, int x, int y) : len(len), x(x), y(y) {}
    };
    int dist(vector<vector<int>> &points, int x, int y) {
        return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<Edge> edges;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                edges.emplace_back(dist(points, i, j), i, j);
            }
        }
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int { return a.len < b.len; });
        int ans = 0, num = 1;
        for(auto &e : edges) {
            if(dsu.merge(e.x, e.y)) {
                ans += e.len;
                num++;
                if(num == n) {
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

