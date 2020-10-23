#include "leetcode-definition.h"
#include <vector>
using namespace std;

#define INPUT "547.txt"

/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution {
    class DSU{
    private:
        vector<int> parent_;
    public:
        DSU(int n) : parent_(n) {
            for(int i = 0; i < n; i++) {
                parent_[i] = i;
            }
        }
        void merge(int x, int y) {
            parent_[find(x)] = find(y); //将x的parent设置成y的parent
        }
        int find(int x) {
            if(parent_[x] != x) {
                return find(parent_[x]);
            }
            return parent_[x];
        }
    };
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(M[i][j]) {
                    dsu.merge(i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dsu.find(i) == i) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

