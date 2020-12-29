#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        
        int ans = 0;
        bool minus = (dividend ^ divisor) < 0; // 用符号位异号来判断最后结果是否是负数
        long divid = labs(dividend);
        long divis = labs(divisor);

        for(int i = 31; i >= 0; i--) {
            if((divid>>i) >= divis ) {
                ans += 1<<i;
                divid -= divis<<i;
            }
        }
        return minus ? (-ans) : ans;
    }
};
// @lc code=end

