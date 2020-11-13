#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "978.txt"
/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        const int n = A.size();
        int ans = 0;
        for(int i = 0; i < n;) {
            int j;
            int tmp = 1;
            int flag = 0; // 记录上一次比较的符号，0:相等， 1:后一个大于前一个，-1:后一个小于前一个
            for(j = i+1; j < n; j++) {
                if(A[j] == A[j-1]) {
                    flag = 0;
                    break;
                } 
                if(A[j] > A[j-1]) {
                    if(flag == 1) {
                        break;
                    } 
                    flag = 1;
                    tmp++;
                } else {
                    if(flag == -1) {
                        break;
                    }
                    flag = -1;
                    tmp++;
                }
            }
            ans = max(ans, tmp);
            if(flag != 0) {
                i = j-1;
            } else {
                i = j;
            }
        }
        return ans;
    } // end maxTurbulenceSize
};
// @lc code=end

