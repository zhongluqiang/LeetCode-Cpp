#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int l = intervals[0][0];
        int r = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {
            const auto &v = intervals[i];
            if(r < v[0]) {
                // 不重叠，无法合并
                ans.push_back({l, r});
                l = v[0];
                r = v[1];
            } else {
                // 合并右区间
                r = max(v[1], r);
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};
// @lc code=end

