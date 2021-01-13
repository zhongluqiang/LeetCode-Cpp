#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
    int rows, cols;
    const vector<int> dirs{-1, 0, 1, 0, -1};
    void dfs(vector<vector<char>> &board, int x, int y) {
        board[x][y] = 'R';
        for(int i = 0; i < 4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i+1];
            if(tx < 0 || ty < 0 || tx >= rows || ty >= cols) {
                continue;
            }
            if(board[tx][ty] != 'O') {
                continue;
            }
            dfs(board, tx, ty);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) { return; }
        rows = board.size();
        cols = board[0].size();

        for(int r = 0, c = 0; c < cols; c++) {
            if(board[r][c] == 'O') {
                dfs(board, r, c);
            }
        }
        for(int r = rows-1, c = 0; c < cols; c++) {
            if(board[r][c] == 'O') {
                dfs(board, r, c);
            }
        }
        for(int r = 0, c = 0; r < rows; r++) {
            if(board[r][c] == 'O') {
                dfs(board, r, c);
            }
        }
        for(int r = 0, c = cols-1; r < rows; r++) {
            if(board[r][c] == 'O') {
                dfs(board, r, c);
            }
        }

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if(board[r][c] == 'R') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
// @lc code=end

