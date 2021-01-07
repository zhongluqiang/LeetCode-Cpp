#include "leetcode-definition.h"
#define INPUT "80.txt"
/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;        // 记录当前有效元素的位置
        int l = 0, r = 0;   // 记录连续相同元素的左右位置
        int skip = 0;       // 记录多少个元素被跳过了

        while(l < nums.size() && r < nums.size()) {
            if(nums[l] == nums[r]) {
                if(l == r || l+1 == r) {
                    nums[cur] = nums[r];
                    cur++;
                    r++;
                } else {
                    skip++;
                    r++;
                }
            } else {
                l = r;
            }
        }

        return nums.size() - skip;
    }
};
// @lc code=end

