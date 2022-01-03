#include "leetcode-definition.h"
#include <regex>
/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start
class Solution {

public:
    string validIPAddress(string queryIP) {
        // (((\d)|([1-9]\d)|(1\d\d)|(2[0-4]\d)|(25[0-5])).){4}
        regex ipv4_pattern("(((\\d)|([1-9]\\d)|(1\\d\\d)|(2[0-4]\\d)|(25[0-5])).){4}"); 
        // (([\da-fA-F]{1,4}):){8}
        regex ipv6_pattern("(([\\da-fA-F]{1,4}):){8}");

        smatch r1, r2;

        string s1 = queryIP + ".";
        string s2 = queryIP + ":";

        if(regex_match(s1, r1, ipv4_pattern)) {
            return "IPv4";
        }
        if(regex_match(s2, r2, ipv6_pattern)) {
            return "IPv6";
        }
        return "Neither";
    }
};
// @lc code=end

