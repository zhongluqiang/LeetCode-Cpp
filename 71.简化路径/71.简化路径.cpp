#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        vector<string> strs;
        string ans = "", tmp = "";
        while(getline(is, tmp, '/')) {
            if(tmp == "" || tmp == ".") {
                continue;
            } else if(tmp == ".." && !strs.empty()) {
                strs.pop_back();
            } else if(tmp != "..") {
                strs.push_back(tmp);
            }
        }
        for(string &s : strs) {
            ans += "/" + s;
        }
        if(ans.empty()) {
            return "/";
        } else {
            return ans;
        }
    }
};
// @lc code=end

