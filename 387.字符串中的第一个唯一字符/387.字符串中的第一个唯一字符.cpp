#include "leetcode-definition.h"
#include <bits/stdc++.h>
#using namespace std;
/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()) {
            return -1;
        }

        vector<int> count(26, 0); // count[i] : a-z出现的次数

        for(int i = 0; i < s.size(); i++) {
            count[s[i]-'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

