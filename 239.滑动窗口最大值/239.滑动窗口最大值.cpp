#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) { return nums; }

        deque<int> q; // 队列保存窗口内单调递减的所有元素，每次遇到新元素时，把队列内比新元素小的所有元素弹出
        vector<int> ans;
        int left = 0, right = 0;
        while(right < nums.size()) {
            while(!q.empty() && nums[right] > q.back()) {
                q.pop_back(); // 进入窗口的值比队尾的元素大就弹出队尾元素
            }
            q.push_back(nums[right++]);
            if(right - left == k) {
                ans.push_back(q.front()); // 队首保存最大值
                if(nums[left++] == q.front()) {
                    q.pop_front(); // 最大值从窗口的队列中移除
                }
            }
        }
        return ans;
    }
};
// @lc code=end

