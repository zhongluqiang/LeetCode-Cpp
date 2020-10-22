#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
using namespace std;

#define INPUT "42.txt"

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if(n == 0) { return 0; }

        int l = 0;
        int r = n - 1;
        int max_l = height[l];
        int max_r = height[r];

        int sum = 0;
        while(l < r) {
            if(max_l < max_r) {
                sum += max_l - height[l];
                ++l;
                max_l = max(max_l, height[l]);
            } else {
                sum += max_r - height[r];
                --r;
                max_r = max(max_r, height[r]);
            }
        }
        return sum;
    }
};
// @lc code=end