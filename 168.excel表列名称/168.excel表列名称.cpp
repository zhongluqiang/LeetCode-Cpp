#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "168.txt"
/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        vector<int> v;
        while(n > 0) {
            int x = n % 26;
            if(x == 0) {
                x = 26;
                n -= x;
            }
            v.insert(v.begin(), x);
            n /= 26;
        }

        string ans;
        for(auto i : v) {
            ans.push_back('A' + i - 1);
        }
        return ans;
    }
};
// @lc code=end

