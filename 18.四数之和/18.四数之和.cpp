#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "18.txt"
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        const int size = nums.size();
        if(size < 4) { return ans; }

        sort(nums.begin(), nums.end());

        // 双指针法，固定num1和num2，num3和num4从首尾向中间移动
        for(int n1 = 0; n1 <= size-4; /*n1++*/) {
            int num1 = nums[n1];
            int sum234 = target - num1;
            for(int n2 = n1+1; n2 <= size-3; /*n2++*/) {
                int num2 = nums[n2];
                int l = n2+1;
                int r = size-1;
                while(l < r) {
                    int num3 = nums[l];
                    int num4 = nums[r];
                    int sum = num2+num3+num4;
                    if(sum == sum234) {
                        ans.push_back({num1, num2, num3, num4});
                        // num3和num4分别移动到下一个不同的值，避免重复结果
                        while(l < r && nums[l] == num3) { l++; }
                        while(l < r && nums[r] == num4) { r--; }
                    } else if (sum < sum234) {
                        l++;
                    } else {
                        r--;
                    }
                }
                // num2移动到下一个不同的值，避免重复结果
                while(n2 <= size-3 && nums[n2] == num2) { n2++; }
            }
            // num1移动到下一个不同的值，避免重复结果
            while(n1 <= size-4 && nums[n1] == num1) { n1++; }
        }
        return ans;
    } // end forSum
};
// @lc code=end

