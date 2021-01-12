#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "1020.txt"
/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
    int rows, cols;
    const vector<int> dirs{-1, 0, 1, 0, -1};

    void bfs(vector<vector<int>> &m, int x, int y) {
        m[x][y] = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int tx = cur.first;
            int ty = cur.second;
            for(int i = 0; i < 4; i++) {
                int ttx = tx + dirs[i];
                int tty = ty + dirs[i+1];
                if(ttx < 0 || tty < 0 || ttx >= rows || tty >= cols) {
                    continue;
                }
                if(m[ttx][tty] == 0) {
                    continue;
                }
                m[ttx][tty] = 0;
                q.push({ttx, tty});
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        rows = A.size();
        cols = A[0].size();

        for(int r = 0, c = 0; c < cols; c++) {
            if(A[r][c]) {
                bfs(A, r, c);
            }
        }
        for(int r = rows-1, c = 0; c < cols; c++) {
            if(A[r][c]) {
                bfs(A, r, c);
            }
        }
        for(int r = 0, c = 0; r < rows; r++) {
            if(A[r][c]) {
                bfs(A, r, c);
            }
        }
        for(int r = 0, c = cols-1; r < rows; r++) {
            if(A[r][c]) {
                bfs(A, r, c);
            }
        }

        int ans = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(A[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

