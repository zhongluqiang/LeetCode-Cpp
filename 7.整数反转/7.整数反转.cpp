#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
#if 0
    int reverse(int x) {
        long result = 0;
        while(x != 0) {
            result = result*10 + x%10;
            x /= 10;
        }
        if(result > INT_MAX || result < INT_MIN) {
            return 0;
        } else {
            return result;
        }
    }
#else
    // 只使用32位有符号整数，无溢出风险
    int reverse(int x) {
        int result = 0;

        bool minus = (x < 0) ? true : false;
        if(minus) {
            if(x == INT_MIN) {
                // 排除INT_MIN，因为-2147483648取反之后已经溢出了
                return 0;
            } else {
                x = -x;
            }
        }

        while(x > 0) {
            // 求和之前排除掉结果溢出的情况，只有保证结果不溢出时才进行下面的运算
            if(result > (INT_MAX - x%10) / 10) {
                return 0;
            } else {
                result = result*10 + x%10;
            }
            x /= 10;
        }
        
        if(minus) {
            return -result;
        } else {
            return result;
        }
    }
#endif    
};
// @lc code=end

