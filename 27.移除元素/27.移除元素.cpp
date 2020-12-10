#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    // 从头查找元素出现的位置，然后把这个元素和最后一个元素对换，再删除最后一个元素，重复该过程直到元素不再出现为止
    // 直接返回vector的大小即可。
    int removeElement(vector<int>& nums, int val) {
        auto it = nums.begin();
        while(it != nums.end()) {
            it = find(nums.begin(), nums.end(), val);
            if(it != nums.end()) {
                swap(*it, nums.back());
                nums.pop_back();
            }
        }
        return nums.size();
    }
};
// @lc code=end

