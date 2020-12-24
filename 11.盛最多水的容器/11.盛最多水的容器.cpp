#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    // 双指针法
    int maxArea(vector<int>& height) {
        int ans = 0;
        int tmp = 0;

        int l = 0, r = height.size() - 1;
        while(l < r) {
            if(height[l] < height[r]) {
                tmp = (r - l) * height[l];
                l++;
            } else {
                tmp = (r - l) * height[r];
                r--;
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};
// @lc code=end

