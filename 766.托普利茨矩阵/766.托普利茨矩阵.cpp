#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();

        for(int c = 1; c < cols; c++) {
            matrix[0][c] ^= matrix[0][c-1];
        }

        for(int r = 1; r < rows; r++) {
            for(int c = 1; c < cols; c++) {
                matrix[r][c] ^= matrix[r][c-1];
                if((matrix[r][c] ^ matrix[r-1][c-1]) != matrix[r][0]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

