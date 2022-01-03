#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        int dir = 0; // 操作方向， 0:左->右，1:右->左
        int step = 1; // 步长，每操作一次乘2
        int left = 1, right = n; 

        while(left < right) {
            int count = (right - left) / step + 1; // 计算当前剩余元素的个数
            if(dir == 0) {
                // 从左向右操作时，左指针必移动一个步长，右指针只在元素个数为奇数时移动
                left += step;
                if(count % 2) {
                    right -= step;
                }
            } else {
                // 从右向左操作时，右指针必移动一个步长，左指针只在元素个数为奇数时移动
                right -= step;
                if(count % 2) {
                    left += step;
                }
            }
            dir = !dir;
            step = step * 2;
        }

        return right; // 左右指针相遇后，返回左或右都可以
    }
};
// @lc code=end

