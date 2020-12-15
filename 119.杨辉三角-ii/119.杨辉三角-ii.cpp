#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    // 滚动数组降维
    vector<int> getRow(int rowIndex) {
        int row = rowIndex + 1;
        vector<int> ans(row);

        for(int i = 0; i < row; i++) {
            if(i == 0 || i == 1) {
                ans[i] = 1;
            } else {
                for(int cur = i; cur >= 0; cur--) {
                    if(cur == i || cur == 0) {
                        ans[cur] = 1;
                    } else {
                        ans[cur] = ans[cur] + ans[cur-1];
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

