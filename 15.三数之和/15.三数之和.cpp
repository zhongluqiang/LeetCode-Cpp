#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
using namespace std;

#define INPUT "15.txt"
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int size = nums.size();
        if(size < 3) { return ans; }

        sort(nums.begin(), nums.end());

        // 双指针法，固定num1，num2和num3从首尾向中移动
        for(int n1 = 0; n1 <= size-3; /**/) {
            int num1 = nums[n1];
            int l = n1+1;
            int r = size-1;
            while(l < r) {
                int num2 = nums[l];
                int num3 = nums[r];
                int sum = num1 + num2 + num3;
                if(sum == 0) {
                    ans.push_back({num1, num2, num3});
                    // 左右指针移动到下一个不同的值，避免结果重复
                    while(l < r && nums[l] == num2) { l++; }
                    while(l < r && nums[r] == num3) { r--; }
                } else if(sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
            // num1移动到下一个不同的值，避免结果重复
            while(n1 <= size-3 && nums[n1]== num1) { n1++; }
        }

        return ans;
    }
};
// @lc code=end

