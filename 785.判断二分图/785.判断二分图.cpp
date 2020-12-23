#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
    vector<int> colors; // 着色表，0：unknown，1：red, -1：green

    bool bfs(vector<vector<int>> &graph, int start) {
        queue<int> q;
        q.push(start);
        colors[start] = 1;

        while(!q.empty()) {
            int size = q.size();
            while(size-- > 0) {
                int cur = q.front(); q.pop();
                for(auto nxt : graph[cur]) {
                    if(colors[nxt] == colors[cur]) {
                        return false;
                    }
                    if(colors[nxt] != 0) {
                        continue;
                    }
                    colors[nxt] = -colors[cur];
                    q.push(nxt);
                }
            }
        }

        return true;
    } // end bfs
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        colors = vector<int>(graph.size(), 0);

        for(int i = 0; i < colors.size(); i++) { 
            if(colors[i]) {
                continue;
            }
            if(!bfs(graph, i)) {
                return false;
            }
        }
        return true;
    } // end isBipartite
};
// @lc code=end

