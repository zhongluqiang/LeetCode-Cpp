#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "74.txt"
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    // 二分查找， 二维坐标转化成一维
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) { return false; }
        int rows = matrix.size();
        int cols = matrix[0].size();

        int mid, low = 0, high = rows*cols-1;
        while(low <= high) {
            mid = low + (high-low) / 2;
            int value = matrix[mid/cols][mid%cols];
            if(value == target) {
                return true;
            } else if(target < value) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return false;
    }
};
// @lc code=end

