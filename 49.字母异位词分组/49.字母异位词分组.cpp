#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> _strs(strs);
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> m;

        for(auto &s : _strs) {
            sort(s.begin(), s.end());
        }

        for(int i = 0; i < strs.size(); i++) {
            m[_strs[i]].push_back(i);
        }

        for(auto &p : m) {
            vector<string> v;
            for(auto i : p.second) {
                v.push_back(strs[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
// @lc code=end

