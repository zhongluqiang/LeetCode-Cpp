#include "leetcode-definition.h"
#include <vector>
#include <pair>
#include <algorithm>
using namespace std;
#define INPUT "1326.txt"
/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

// @lc code=start
class Solution {

public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> p(n+1);

        for(int i = 0; i <= n; i++) {
            p[i].first = (i-ranges[i] < 0 ? 0 : i-ranges[i]);
            p[i].second = (i+ranges[i] > n ? n : i+ranges[i]);
        }
        sort(p.begin(), p.end());

        int ans = 0;
        int r = 0, i = 0;
        while(r < n) {
            int mx = -1;
            while(i < p.size() && p[i].first <= r) {
                mx = max(mx, p[i].second);
                i++;
            }
            if(mx == -1) {
                return -1;
            }
            ans++;
            r = mx;
        }

        return ans;
    } // end minTaps
};
// @lc code=end

