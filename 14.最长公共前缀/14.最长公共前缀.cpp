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
        string ans;

        // 统计最长公共前缀的最大值，对应最短的字符串的长度，最公共前缀不会超过这个长度
        int maxCommLen = INT_MAX;
        for(int i = 0; i < size; i++) {
            if(maxCommLen > strs[i].size()) {
                maxCommLen = strs[i].size();
            }
        }
        if(maxCommLen == 0 || maxCommLen == INT_MAX) {
            return ans;
        }

        // 逐个比较得出最长公共前缀
        for(int i = 0; i < maxCommLen; i++) {
            for(int j = 0; j < size-1; j++) {
                if(strs[j][i] != strs[j+1][i]) {
                    return ans;
                }
            }
            ans.push_back(strs[0][i]);
        }

        return ans;
    } // end longestCommonPrefix
};
// @lc code=end

