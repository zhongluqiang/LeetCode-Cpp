#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
    // 字符串分割，可非常容易地改成以字符串为分割点
    vector<string> split(string &s, char delimeter) {
        vector<string> v;
        string::size_type pos1, pos2;
        pos1 = 0;
        pos2 = s.find(delimeter);
        while(pos2 != string::npos) {
            v.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2 + 1; // 如果以字符串为分割点，则 pos1 = pos2 + delimeter.size()
            pos2 = s.find(delimeter, pos1);
        }
        if(pos1 != s.size()) {
            v.push_back(s.substr(pos1));
        }
        return v;
    }
public:
    bool wordPattern(string pattern, string s) {
        vector<string> substrs = split(s, ' ');
        if(substrs.size() != pattern.size()) {
            return false;
        }
        
        // 两个map，对应字母到字符串的映射和字符串到字母的映射，两个映射都必须唯一
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;

        for(int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string str = substrs[i];
            
            // 要么映射都存在且相等，要么都不存在，否则其他情况都返回false
            if(m1.count(ch) > 0 && m2.count(str) > 0) {
                if(m1[ch] == str && m2[str] == ch) {
                    continue;
                } else {
                    return false;
                }
            }

            if(m1.count(ch) == 0 && m2.count(str) == 0) {
                m1[ch] = str;
                m2[str] = ch;
                continue;
            }
            
            return false;
        }
        return true;
    }
};
// @lc code=end

