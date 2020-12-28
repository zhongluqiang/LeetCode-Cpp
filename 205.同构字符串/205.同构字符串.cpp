#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> s2t;
        unordered_map<int, int> t2s;
        
        for(int i = 0, len = s.size(); i < len; i++) {
            int x = s[i], y = t[i];
            if((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};
// @lc code=end

