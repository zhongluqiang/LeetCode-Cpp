#include <bits/stdc++.h>
using namespace std;0
/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) { return -1; }
        vector<int> sum(n+1, 0); // 前缀和, sum[i] = sum{nums[0]~nums[i-1]}
        for(int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            if(sum[i] == sum[n] - sum[i+1]) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

