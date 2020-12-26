#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "85.txt"
/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
    // 84.柱状图中的最大矩形题解
    int largestRectangleArea(vector<int> &heights) {
        int ans = 0;
        stack<int> s;
        s.push(0);

        for(int i = 1; i < heights.size(); i++) {
            while(!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                ans = max(ans, (i - s.top() - 1) * h);
            }
            s.push(i);
        }
        
        return ans;
    }
public:
    // 计算每矩阵每行的柱形图，用84题求柱形图最大矩形的方法求解每行中的最大矩形，返回所有行的最大值
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        vector<vector<int>> heights(rows+1, vector<int>(cols+2, 0)); // 首部插入一行全0，每行前尾插入0，方便计算

        // 计算矩阵每行的柱形图
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == '1') {
                    heights[i+1][j+1] = heights[i][j+1] + 1;
                }
            }
        }

        // 求每行的柱形图的最大矩形面积
        int ans = INT_MIN;
        for(int i = 0; i < rows + 1; i++) {
            ans = max(ans, largestRectangleArea(heights[i]));
        }


        return ans;
    } // end maximalRectangle
};
// @lc code=end

