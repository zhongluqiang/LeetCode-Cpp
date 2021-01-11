#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int size = nums.size();
        vector<string> ans;
        int i = 0;
        while (i < size) {
            int low = i;
            i++;
            while (i < size && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

