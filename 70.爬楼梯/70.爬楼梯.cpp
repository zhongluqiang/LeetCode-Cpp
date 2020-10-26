#include "leetcode-definition.h"
#include <vector>
using namespace std;
#define INPUT "70.txt"
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) {
            return n;
        }

        // 从第3步开始，用前两步的解来递推
        int cur;    //当前解法，前两步解法的和
        int one = 2; //1步之前的解
        int two = 1; //2步之前的解

        for(int i = 3; i <= n; i++) {
            cur = one + two;
            two = one;
            one = cur;
        }
        return cur;
    }
};
// @lc code=end

