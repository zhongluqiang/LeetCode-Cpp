#include "leetcode-definition.h"
#include<bits/stdc++.h>
using namespace std;
#define INPUT "830.txt"
/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        if(s.size() < 3) {
            return ans;
        }
        set<vector<int>> ans_set;
        int cur = 0;
        int i, len;
        for(i = 1, len = s.size(); i < len; i++) {
            if(s[i] != s[cur]) {
                if(i-cur < 3) {
                    cur = i;
                    continue;
                } else {
                    ans_set.insert({cur, i-1});
                    cur = i;
                }
            }
        }
        if(s[i-1] == s[cur] && i-cur >= 3) {
            ans_set.insert({cur, i-1});
        }
        ans.resize(ans_set.size());
        copy(ans_set.begin(), ans_set.end(), ans.begin());
        return ans;
    }
};
// @lc code=end

