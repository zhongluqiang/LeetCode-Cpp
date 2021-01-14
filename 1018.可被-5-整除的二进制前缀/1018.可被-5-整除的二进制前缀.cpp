#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "1018.txt"
/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int x = 0;
        for(auto i : A) {
            x = ((x << 1) + i) % 5;
            ans.push_back(!x);
        }
        return ans;
    }
};
// @lc code=end

