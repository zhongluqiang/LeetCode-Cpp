#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int size = matrix.size();
        for(int i = 0; i < size/2; i++) {
            swap(matrix[i], matrix[size-i-1]);
        }
        for(int i = 0; i < size; i++) {
            for(int j = i; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end

