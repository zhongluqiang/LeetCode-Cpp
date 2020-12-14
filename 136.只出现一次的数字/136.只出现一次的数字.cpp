#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            nums[0] = nums[0] ^ nums[i];
        }
        return nums[0];
    }
};
// @lc code=end

