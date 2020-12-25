#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;

        for(int x = 0, y = 0; x < g.size() && y < s.size();x++, y++) {
            while(y < s.size() && s[y] < g[x]) {
                y++;
            }
            if(y == s.size()) {
                return ans;
            }
            ans++;
        }
        return ans;
    }
};
// @lc code=end

