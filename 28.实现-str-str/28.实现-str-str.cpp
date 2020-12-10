#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "28.txt"
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    // 朴素比较法，从头开始比较，遇到不匹配时搜索词往后移一位，O(n*m)时间复杂度
    int strStr(string haystack, string needle) {
        if(needle.empty()) {
            return 0;
        }
        const char *s1  = haystack.c_str();
        const char *s2  = needle.c_str();
        const char *start = s1;
        const char *p1, *p2;
        while (*start != '\0') {
            p1 = start;
            p2 = s2;
            while (*p1 &&*p2 &&*p1 == *p2) {
                p1++;
                p2++;
            }
                ;
            if(!*p2) {
                return start - s1;
            }
            if(!*p1) {
                return -1;
            }
            start++;
        }
        return -1;
    } // end strStr
};
// @lc code=end

