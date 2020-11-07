#include <vector>
#include <queue>
using namespace std;
#define INPUT "886.txt"
/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
#if DFS
class Solution {
    vector<vector<int>> graph; // 无向图的邻接数组表示法，graph[i]表示与i结点相邻的所有结点构成的数组
    vector<int> colors; // colors[i]表示第i个结点的颜色，1为红色，-1为蓝色，初始时为0，表示未知

    // 递归对cur结点和与其相邻的结点进行染色
    bool dfs(int cur, int color) {
        // 先将当前结点进行染色
        colors[cur] = color;
        // 遍历当前结点的邻结点，如果已经染色，判断颜色是否冲突，如果未染色，对邻结点递归进行染色，看能否完成染色
        for(int nxt : graph[cur]) {
            if(colors[nxt] == color) {
                return false;
            }
            if(colors[nxt] == 0 && !dfs(nxt, -color)) {
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(N);
        // 构建无向图，如果dislikes数量远小于N，那么这里就是个稀疏图，可以改用其他更高效的表示
        for(const auto &d : dislikes) {
            graph[d[0] - 1].push_back(d[1] - 1);
            graph[d[1] - 1].push_back(d[0] - 1);
        }
        // 初始化所有结点的颜色为未知
        colors = vector<int>(N, 0); // 0:unknown, 1:red, -1:blue

        // 对所有结点进行染色，因为染色是递归的，所以一旦i位置的结点颜色不为0，那表示i结点及其子结点都被染色了
        // 其实并不需要对所有结点进行染色，只需要对dislikes里存在的结点进行染色就可以了，中立的结点不管怎么染色都不影响分组
        for(int i = 0; i < N; i++) {
            if(colors[i] == 0 && !dfs(i, 1)) {
                return false;
            }
        }

        return true;
    }
};
#else // BFS
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(N);
        for(const auto &d : dislikes) {
            g[d[0] - 1].push_back(d[1] - 1);
            g[d[1] - 1].push_back(d[0] - 1);
        }

        queue<int> q; // 广度遍历使用队列实现
        vector<int> colors(N, 0); // 0:unknown, 1:red, -1:blue

        for(int i = 0; i < N; i++) {
            if(colors[i] != 0) {
                continue;
            }
            q.push(i);
            colors[i] = 1;
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                for(int nxt : g[cur]) {
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
    }
};
#endif
// @lc code=end

