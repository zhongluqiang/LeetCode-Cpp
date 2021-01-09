#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        for(int i = 0, len = 1<<n; i < len; i++) {
            ans[i] = i ^ i>>1;
        }
        return ans;
    }
};
// @lc code=end

