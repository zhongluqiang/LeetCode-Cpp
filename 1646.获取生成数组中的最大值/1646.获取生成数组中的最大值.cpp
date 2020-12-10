#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0 || n == 1) {
            return n;
        }

        vector<int> nums(n+1);
        nums[0] = 0;
        nums[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(i%2 == 0) {
                nums[i] = nums[i/2];
            } else {
                nums[i] = nums[i/2] + nums[i/2 + 1];
            }
        }
        return *max_element(nums.begin(), nums.begin() + n + 1);
    }
};
// @lc code=end

