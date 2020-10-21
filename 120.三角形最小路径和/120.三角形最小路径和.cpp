#include "leetcode-definition.h"
#include <vector>
#include <cstdio>
using namespace std;

#define INPUT "120.txt"
/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result;
        int size = triangle.size();
        if(size < 2) { return triangle[0][0]; }

        int *sum = new int[size];

        sum[0] = triangle[0][0];
        for(int i = 1; i <= size-1; i++) { // 每轮循环之后，sum存储第i行的结果
            for(int j = i; j >= 0; j--) {  // 第二轮循环要从最后一位开始，避免sum[j-1]被提前修改
                if(j == 0) {
                    sum[j] = sum[j] + triangle[i][j];
                } else if(j == i) {
                    sum[j] = sum[j-1] + triangle[i][j];
                } else {
                    sum[j] = min(sum[j-1], sum[j]) + triangle[i][j];
                }
            }
        }

        // 结果存在最后一行，找出最小值即可
        result = sum[0];
        for(int i = 1; i <= size - 1; i++) {
            if(result > sum[i]) {
                result = sum[i];
            }
        }
        delete []sum;
        return result;
    }
};
// @lc code=end

