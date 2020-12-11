#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        const int size = s.size();
        if(size == 0) {
            return 0;
        }
        int ans = 0;
        while(s.size() > 0 && s.back() == ' ') {
            s.pop_back();
        }
        while(s.size() > 0 && s.back() != ' ') {
            ans++;
            s.pop_back();
        }
        return ans;
    }
};
// @lc code=end

