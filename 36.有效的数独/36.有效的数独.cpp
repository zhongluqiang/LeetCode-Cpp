#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
    inline int getGrid(int x, int y) {
        static vector<int> index = {0, 0, 0, 1, 1, 1, 2, 2, 2};
        int row = index[x];
        int col = index[y];
        return row*3 + col;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row_index(9, vector<int>(10, 0));    // row_index[i][j]表示在第i行数字j是否出现过
        vector<vector<int>> line_index(9, vector<int>(10, 0));   // line_index[i][j]表示在第i列数字j是否出现过
        vector<vector<int>> grid_index(9, vector<int>(10, 0));   // grid_index[i][j]表示在第i个格子数字j是否出现过
        
        int x, grid;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                x = board[i][j];
                if(x == '.') {
                    continue;
                }
                grid = getGrid(i, j);
                //printf("i=%d, j=%d, grid=%d\n", i, j, grid);
                if(row_index[i][x-'0'] || line_index[j][x-'0'] || grid_index[grid][x-'0']) {
                    return false;
                }
                row_index[i][x-'0'] = 1;
                line_index[j][x-'0'] = 1;
                grid_index[grid][x-'0'] = 1;
            }
        }
        return true;
    }
};  
// @lc code=end

