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
        unordered_map<int, int> index; // 值 -> 下标
        for(int i = 0; i < numbers.size(); i++) {
            index[numbers[i]] = i+1;
        }

        for(int i = 0; i < numbers.size(); i++) {
            if(index.count(target - numbers[i]) > 0) {
                return {i+1, index[target-numbers[i]]};
            }
        }

        return {0, 0};
    }
};
// @lc code=end

