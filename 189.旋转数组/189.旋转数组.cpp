#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int size = nums.size();
        k = k % size;
        reverse(nums.begin(), nums.end());            // 以右移3次为例，12345 -> 54321
        reverse(nums.begin(), nums.begin() + k);      // 54321 -> 34521
        reverse(nums.begin()+k, nums.end());          // 34521 -> 34512
    }
};
// @lc code=end

