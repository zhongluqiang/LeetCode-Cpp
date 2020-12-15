#include "leetcode-definition.h"
#define INPUT "69.txt"
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
         if(x == 0) {
             return 0;
         }
         
         int low = 1;
         int high = x;
         long long mid = low + (high - low) / 2;
         while(low <= high) {
             long long k = mid * mid;
             if(k == x) {
                 return mid;
             } else if(k > x) {
                 high = mid-1;
             } else {
                 low = mid+1;
             }
             mid = low + (high - low) / 2;
         }
         return high;
    }
};
// @lc code=end

