#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
    static inline bool isPalindrome(string &s) {
        if(s.empty()) {
            return false;
        }
        int x = 0, y = s.size() - 1;
        while(x <= y) {
            if(s[x] != s[y]) {
                return false;
            }
            x++;
            y--;
        }
        return true;
    }

    vector<vector<string>> ans;
    // 求[start,end]区间的回文子串，temp是[0~start]已有的回文子串
    void dfs(string &s, int start, int end, vector<string> &temp) {
        if(start > end) {
            ans.push_back(temp);
            return;
        }
        for(int i = start; i <= end; i++) {
            string str = s.substr(start, i-start+1);
            if(!isPalindrome(str)) {
                continue;
            }
            temp.push_back(str);
            dfs(s, i+1, end, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) { return ans; }
        vector<string> temp;
        dfs(s, 0, s.size()-1 , temp);
        return ans;
    }
};
// @lc code=end

