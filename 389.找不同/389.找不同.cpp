#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    // 统计字符串s+t中每个字母出现的次数，出现奇数次的一定是被添加的字母
    char findTheDifference(string s, string t) {
        int count[26] = {0};
        for(auto ch : s) {
            count[ch - 'a']++;
        }
        for(auto ch : t) {
            count[ch - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i]&0x1) {
                return 'a'+i;
            }
        }
        return 0; // never here
    }
};
// @lc code=end

