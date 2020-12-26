#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "16.txt"
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int difference = INT_MAX;
        int a = nums[0], b = nums[1], c = nums[2];

        for(int i = 0; i < nums.size()-2; i++) {
            for(int j = i+1; j < nums.size()-1; j++) {
                for(int k = j+1; k < nums.size(); k++) {
                    int diff = abs(target - nums[i] - nums[j] - nums[k]);
                    if(diff == 0) {
                        return target;
                    }
                    if(diff < difference) {
                        difference = diff;
                        a = nums[i];
                        b = nums[j];
                        c = nums[k];
                    }
                    if(nums[i] + nums[j] + nums[k] > target) {
                        break;
                    }
                }
                if(nums[i] + nums[j] + nums[j+1] >= target) {
                    break;
                }
            }
            if(nums[i] + nums[i+1] + nums[i+2] >= target) {
                break;
            }
        }
        return a+b+c;
    }
};
// @lc code=end

