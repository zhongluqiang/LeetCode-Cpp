#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
    vector<vector<int>> graph;
    vector<bool> visited;

    void dfs(int n) {
        if(visited[n]) {
            return;
        }
        visited[n] = true;
        for(int nxt : graph[n]) {
            dfs(nxt);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        graph = rooms;
        visited = vector<bool>(n, false);
        dfs(0);
        for(auto b : visited) {
            if(!b) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

