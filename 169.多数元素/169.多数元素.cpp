#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int size = nums.size();
        unordered_map<int, int> count;

        for(auto i : nums) {
            count[i]++;
        }

        for(auto p : count) {
            if(p.second > size / 2) {
                return p.first;
            }
        }

        return 0; // never here
    }
};
// @lc code=end

