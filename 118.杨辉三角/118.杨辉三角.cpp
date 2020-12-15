#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "118.txt"
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row = 1; row <= numRows; row++) {
            if(row == 1) {
                ans.push_back({1});
            } else if(row == 2) {
                ans.push_back({1, 1});
            } else {
                vector<int> cur(row);
                cur[0] = cur[row-1] = 1;
                for(int j = 1; j <= row-2; j++) {
                    cur[j] = ans[row-2][j-1] + ans[row-2][j];
                }
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
// @lc code=end

