#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    // 用a,b来共同记录一个数出现3次以内的所有状态，初始时a,b都为0，表示这个数没出现过
    // 当出现一次时，用a来表示，当出现两次时，用b来表示，当出现3次时，a,b又回到0
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto num : nums) {
            a = (a ^ num) & ~b;
            b = (b ^ num) & ~a;
        }
        return a;
    }
};
// @lc code=end

