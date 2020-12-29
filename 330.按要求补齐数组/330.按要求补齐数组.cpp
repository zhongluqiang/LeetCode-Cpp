#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long cur_range = 0; // 当前能覆盖到的最远区间
        const int size = nums.size();
        int ans = 0;

        // pos指向nums下标，i表示当前能覆盖的最大区间
        for(long i = 1, pos = 0; i <= n; /**/) {
            if(pos >= size || i < nums[pos]) {
                ans++;
                cur_range += i;
            } else {
                cur_range += nums[pos];
                pos++;
            }

            i = cur_range + 1;
        }
        return ans;
    }
};
// @lc code=end

