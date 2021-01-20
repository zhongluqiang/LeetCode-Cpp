#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {

public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int max1 = nums[0]*nums[1]*nums[2];
        int max2 = nums[0]*nums[nums.size()-1]*nums[nums.size()-2];
        return max(max1, max2);
    }
};
// @lc code=end

