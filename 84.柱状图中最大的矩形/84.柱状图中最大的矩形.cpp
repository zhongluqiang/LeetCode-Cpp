#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "84.txt"
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#if 0
class Solution {
public:
    // 暴力解法，遍历每根柱子，找柱子两边从哪个点开始走下坡路，柱子的高度
    // 乘以两个走下坡路的点的距离就是这个柱子能构成的最大矩形的面积
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) {
            return 0;
        }

        int ans = INT_MIN;
        for(int i = 0; i <heights.size(); i++) {
            int cur = heights[i];
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && heights[left] >= cur) {
                left--;
            }
            left = left + 1;
            while(right < heights.size() && heights[right] >= cur) {
                right++;
            }
            right = right - 1;
            ans = max(ans, (right - left + 1) * cur);
        }
        return ans;
    }
};
#else
class Solution {
public:
    // 单调栈解法，维护一个单调递增栈（当入栈较小元素时，要先把栈中比这个元素小的所有元素依次出栈，以保证整个栈的元素是单调递增的）
    // 遇到第i个柱子时，如果栈顶的柱子比当前的柱子大，那么对栈顶的柱子来说，相当于直接找到了它两侧比它小的柱子，可以直接计算栈顶柱的面积
    // 入栈和出栈的是柱子的下标，不是元素
    int largestRectangleArea(vector<int>& heights) {
        // 数组首尾插入0，方便计算
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        
        int ans = 0;
        stack<int> s;
        s.push(0);

        for(int i = 1; i < heights.size(); i++) {
            // 栈顶的柱子比要入栈的柱子高，那么可以直接计算栈顶柱子的面积
            // 下一个栈顶元素-当前栈顶元素-即将入栈元素 构成 低-高-低形状，中间的矩形面积就是确定的
            while(!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                ans = max(ans, (i - s.top() - 1) * h);
            }
            s.push(i);
        }
        
        return ans;
    }
};
#endif
// @lc code=end

