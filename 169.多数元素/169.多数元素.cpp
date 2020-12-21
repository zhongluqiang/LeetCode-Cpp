#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    // 摩尔投票法
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == major) {
                count++;
            } else {
                count--;
                if(count == 0) {
                    major = nums[i];
                    count = 1;
                }
            }
        }
        return major;
    }
};
// @lc code=end

