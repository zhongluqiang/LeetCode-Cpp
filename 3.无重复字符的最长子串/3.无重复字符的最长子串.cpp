#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口法，右指针移动，维护当前窗口内容，如果窗口内出现重复元素，则移动左子指针直到无重复元素
    // 右指针一次移动一步从头移到尾，每次出现重复元素时移动左指针以维护窗口
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }

        int left = 0;
        int ans = 1;
        unordered_set<int> lookup;

        for(int i = 0; i < s.size(); i++) {
            while(lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                left++;
            }
            ans = max(ans, i-left+1);
            lookup.insert(s[i]);
        }
        return ans;
    }
};
// @lc code=end

