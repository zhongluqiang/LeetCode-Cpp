#include <vector>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
    // sum[i][j]表示区域(1,1)到(i+1,j+1)的和
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows, cols;
        rows = matrix.size();
        if(rows > 0) {
            cols = matrix[0].size();
        }
        // 在矩阵左边和上边增加一行空白行，方便计算
        sum = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        for(int r = 1; r <= rows; r++) {
            for(int c = 1; c <= cols; c++) {
                sum[r][c] = matrix[r-1][c-1] + sum[r][c-1] + sum[r-1][c] - sum[r-1][c-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

