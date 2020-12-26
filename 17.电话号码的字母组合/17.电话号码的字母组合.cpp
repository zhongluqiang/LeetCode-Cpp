#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    map<int, vector<string>> index = {
        {'2', {"a","b","c"}},
        {'3', {"d","e","f"}},
        {'4', {"g","h","i"}},
        {'5', {"j","k","l"}},
        {'6', {"m","n","o"}},
        {'7', {"p","q","r","s"}},
        {'8', {"t","u","v"}},
        {'9', {"w","x","y","z"}}
    };

    vector<string> fuck(string digits) {
        vector<string> ans;
        if(digits.empty()) {
            // nothing to do
        } else if(digits.size() == 1) {
            ans = index[digits[0]];
        } else {
            vector<string> v = fuck(digits.substr(1));
            for(auto &s1 : index[digits[0]]) {
                for(auto &s2 : v) {
                    ans.push_back(s1 + s2);
                }
            }
        }
        return ans;
    }

public:
    vector<string> letterCombinations(string digits) {
        return fuck(digits);
    }
};
// @lc code=end

