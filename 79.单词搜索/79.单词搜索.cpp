#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
    const vector<int> dirs = {-1, 0, 1, 0, -1};
    bool dfs(vector<vector<char>> &board, int x, int y, string &temp, vector<vector<int>> &used, const string &word) {
        if(word.find(temp) != 0) {
            return false;
        }
        if(temp == word) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int tx = x+dirs[i];
            int ty = y+dirs[i+1];
            if(tx < 0 || ty < 0 || tx >= board.size() || ty >= board[0].size()) {
                continue;
            }
            if(used[tx][ty]) {
                continue;
            }
            temp.push_back(board[tx][ty]);
            used[tx][ty] = 1;
            if(dfs(board, tx, ty, temp, used, word)) {
                return true;
            }
            temp.pop_back();
            used[tx][ty] = 0;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int rows = board.size();
        const int cols = board[0].size();
        vector<vector<int>> used(rows, vector<int>(cols, 0));
        string temp;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                temp.push_back(board[i][j]);
                used[i][j] = 1;
                if(dfs(board, i, j, temp, used, word)) {
                    return true;
                }
                temp.pop_back();
                used[i][j] = 0;
            }
        }
        return false;
    }
};
// @lc code=end

