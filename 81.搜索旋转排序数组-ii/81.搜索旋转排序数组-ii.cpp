#include "leetcode-definition.h"
#define INPUT "81.txt"
/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) { return false; }
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low <= high) {
            // 处理左右两边数字相同的情况，要保证左右两边的数字不一样，才能通过中间点的值来判断哪部分是排序好的
            // 比如[1, 0, 1, 1, 1]，这个case仅通过中间点就无法判断哪部分是排序好的
            while(low <= high && nums[low] == nums[high] && nums[low] != target) {
                low++;
                high--;
            }
            if(low > high) {
                return false;
            }
            if(nums[low] == target || nums[high] == target) {
                return true;
            }

            mid = low + (high-low) / 2;
            if(nums[mid] == target) {
                return true;
            }

            if(nums[mid] >= nums[low]) {
                // 左半部分是排序好的
                if(target > nums[low] && target < nums[mid]) {
                    // target落在左半边
                    high = mid-1;
                } else {
                    // target落在右半边
                    low = mid+1;
                }
            } else {
                // 右半部分是排序好的
                if(target > nums[mid] && target < nums[high]) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return false;
    }
};
// @lc code=end

