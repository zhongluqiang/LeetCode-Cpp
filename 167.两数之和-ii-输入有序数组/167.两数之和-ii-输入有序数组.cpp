#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left <= right) {
            if(numbers[left] + numbers[right] == target) {
                return {left+1, right+1};
            }
            if(numbers[left] + numbers[right] > target) {
                right--;
            } else {
                left++;
            }
        }
        return {0, 0};
    }
};
// @lc code=end

