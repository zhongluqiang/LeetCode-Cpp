#include "leetcode-definition.h"
#include <bits/stdc++.h>
#define INPUT "50.txt"
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1.0;
        }

        if(fabsl(fabsl(x) - 1.0) < 1e-6) {
            if(x > 0) {
                return 1.0;
            } else {
                return n%2 == 0 ? 1.0 : -1.0;
            }
        }

        double ans = 1.0;
        bool minus = (n < 0);
        n = abs(n);
        for(long i = n; i > 0; i = i>>1) {
            if(i&0x1 == 1) {
                ans *= x;
            }
            x *= x;
        }
        return minus ? (1/ans) : ans;
    }
};
// @lc code=end

