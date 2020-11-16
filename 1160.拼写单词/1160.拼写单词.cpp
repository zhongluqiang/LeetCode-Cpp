#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "1160.txt"
/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
 */

// @lc code=start
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unsigned count_[255] = {0};
        for(unsigned ch : chars) {
            count_[ch]++;
        }

        bool ok;
        int ans = 0;
        unsigned count[255];
        for(auto w : words) {
            ok = true;
            memcpy(count, count_, sizeof(count_));
            for(auto ch : w) {
                if(count[ch]) {
                    count[ch]--;
                } else {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans += w.size();
            }
        }
        return ans;
    }
};
// @lc code=end

