#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int size = nums.size();
        if(size == 0) {
            return -1;
        }

        int l = 0, r = size-1;
        while(l <= r) {
            if(nums[l] == target) {
                return l;
            } else {
                l++;
            }
            if(nums[r] == target) {
                return r;
            } else {
                r--;
            }
        }
        return -1;
    }
};
// @lc code=end

