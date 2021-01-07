#include "leetcode-definition.h"
#define INPUT "54.txt"
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
    vector<int> spiralOrderRecursive(vector<vector<int>> &m, int x1, int y1, int x2, int y2) {
        if(x1 > x2 || y1 > y2) {
            return {};
        }
        vector<int> ans1, ans2;
        for(int y = y1; y <= y2; y++) {
            ans1.push_back(m[x1][y]);
        }
        for(int x = x1+1; x <= x2; x++) {
                ans1.push_back(m[x][y2]);
        }
        if(x1 != x2) {
            for(int y = y2-1; y >= y1; y--) {
                ans1.push_back(m[x2][y]);
            }
        }
        if(y1 != y2) {
            for(int x = x2-1; x >= x1+1; x--) {
                ans1.push_back(m[x][y1]);
            }
        }
        ans2 = spiralOrderRecursive(m, x1+1, y1+1, x2-1, y2-1);
        for(auto i : ans2) {
            ans1.push_back(i);
        }
        return ans1;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return spiralOrderRecursive(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1);
    }
};
// @lc code=end

