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
            // 若映射不存在，则先构造s和t的映射
            if(s2t.count(x) == 0) {
                s2t[x] = y;
            }
            if(t2s.count(y) == 0) {
                t2s[y] = x;
            }
            // 映射必须存在且为相互映射
            if(s2t[x] != y || t2s[y] != x) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

