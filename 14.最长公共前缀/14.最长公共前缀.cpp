#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "14.txt"
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int size = strs.size();
        if(size == 0) {
            return "";
        }
        // 按字典序从小到大排序，再求最小串与最大串的最长公共前缀就是全部串的最长公共前缀
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[size - 1];
        string ans;
        for(int i = 0; i < min(s1.size(), s2.size()); i++) {
            if(s1[i] != s2[i]) {
                return ans;
            } else {
                ans.push_back(s1[i]);
            }
        }
        
        return ans;
    } // end longestCommonPrefix
};
// @lc code=end

