#include "leetcode-definition.h"

#include <bits/stdc++.h>
using namespace std;
#define INPUT "861.txt"
/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution {
public:
    /*
     * 求和时最左一列的权值最大，最右一列的权值最小
     * 先通过行翻转使第一列全部为1，然后对后续的列进行列翻转，保证翻转之后该列的1比0多就可以
     * 第一列通过行翻转总是能全部翻转成1，后续的列每次用列翻转，并且每次翻转都是独立的
    */
    int matrixScore(vector<vector<int>>& A) {
        const int rows = A.size();
        const int colums = A[0].size();
        vector<unsigned long long> weight(colums, 0); // 先计算出第一列到最后一列的权值，weight[i]表示第i列的权值
        weight[colums-1] = 1;
        for(int i = colums-2; i >= 0; i--) {
            weight[i] = weight[i+1] << 1;
        }

        // 先通过行翻转将第一列全变成1
        for(int i = 0; i < rows; i++) {
            if(A[i][0]) {
                continue;
            }
            for(int j = 0; j < colums; j++) {
                A[i][j] = !A[i][j];
            }
        }

        unsigned long long ans = 0;
        ans += rows * weight[0]; //第一列总是可以通过行翻转变成1

        // 从第二列开始，统计每列的1多还是0多，哪个多就用哪个来计算这列的结果
        int zeros, ones;
        for(int i = 1; i < colums; i++) {
            zeros = 0;
            ones = 0;
            for(int j = 0; j < rows; j++) {
                if(A[j][i]) {
                    ones++;
                } else {
                    zeros++;
                }
            }
            ans += max(zeros, ones) * weight[i];
        }
        return ans;
    } // end matrixScore
};
// @lc code=end

