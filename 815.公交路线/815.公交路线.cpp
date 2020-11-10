#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

// @lc code=start
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T) {
            return 0;
        }

        // 站点编号 -> 当前站点有哪些公交线路
        unordered_map<int, vector<int>> m; 
        for(int i = 0; i < routes.size(); i++) {
            for(const int stop : routes[i]) {
                m[stop].push_back(i);
            }
        }

        // 记录每条公交线路是否被使用过
        vector<int> ride(routes.size(), 0);
        queue<int> q;
        q.push(S);
        int ans = 0;
        
        while (!q.empty()) {
            int size = q.size();
            ++ans;
            while(size--) {
                int cur = q.front();
                q.pop();
                for(const int bus : m[cur]) {
                    if(ride[bus]) {
                        continue;
                    }
                    ride[bus] = 1;
                    for(int stop : routes[bus]) {
                        if(stop == T) {
                            return ans;
                        }
                        q.push(stop);
                    }
                }
            }
        }
        
        return -1;
    } // end numBusesToDestination
};
// @lc code=end

