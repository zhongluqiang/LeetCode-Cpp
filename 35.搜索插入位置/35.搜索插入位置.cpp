#include <bits/stdc++.h>
using namespace std;
#define INPUT "35.txt"
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right) {
            //int mid = (left + right) / 2;
            int mid = left + (right-left) / 2; // 用这种写法，防止(left+right)溢出
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};
// @lc code=end

