#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "1147.txt"
/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

// @lc code=start
class Solution {
    int decompisition(const char s[], int l, int r) {
        if(l == r) {
            return 1;
        }
        if(l > r) {
            return 0;
        }
        int i;
        bool found = false;
        for(i = 1; l+i-1 < r-i+1; i++) {
            if(strncmp(s+l, s+r-i+1, i) == 0) {
                found = true;
                break;
            }
        }
        if(!found) {
            return 1;
        }
        return 2 + decompisition(s, l+i, r-i);
    }
public:
    int longestDecomposition(string text) {
        const char *s = text.c_str();
        return decompisition(s, 0, strlen(s) - 1);
    }
};
// @lc code=end

