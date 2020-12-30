#include <bits/stdc++.h>
using namespace std;
#define INPUT "75.txt"
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    // 两轮遍历，先把所有的0交换到数组首部，再把所有的1交换到0后面，2不用管
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        for(int i = ptr; i < n; i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
    } // end sortColors
};
// @lc code=end

