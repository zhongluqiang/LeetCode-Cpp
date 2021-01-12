#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "93.txt"
/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
    vector<string> ans;
    
    void dfs(string s, int start, vector<string> &temp) {
        if(start == s.size()) {
            if(temp.size() == 4) {
                string str;
                str += temp[0];
                for(int i = 1; i <= 3; i++) {
                    str += ".";
                    str += temp[i];
                }
                ans.push_back(str);
            }
            return;
        }
        if(temp.size() >= 4) {
            return;
        }

        if(!isdigit(s[start])) {
            return;
        }

        if(s[start] == '0') {
            temp.push_back("0");
            dfs(s, start+1, temp);
            temp.pop_back();
            return;
        }

        temp.push_back(s.substr(start, 1));
        dfs(s, start+1, temp);
        temp.pop_back();

        if(start != s.size() - 1) {
            temp.push_back(s.substr(start, 2));
            dfs(s, start+2, temp);
            temp.pop_back();
        }
        if(start != s.size() - 2) {
            string str = s.substr(start, 3);
            try {
                int num = stoi(str);
                if(stoi(str) > 0 && stoi(str) <= 255) {
                    temp.push_back(str);
                    dfs(s, start+3, temp);
                    temp.pop_back();
                }
            } catch (...) {

            }
            
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> temp;
        dfs(s, 0, temp);
        return ans;
    }
};
// @lc code=end

