#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if(i < m) {
            while(i < m) {
                ans.push_back(nums1[i]);
                i++;
            }
        }
        if(j < n) {
            while(j < n) {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        copy(ans.begin(), ans.end(), nums1.begin());
    }
};
// @lc code=end

