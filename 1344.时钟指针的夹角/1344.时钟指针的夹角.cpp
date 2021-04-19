#include <bits/stdc++.h>>
using namespace std;
/*
 * @lc app=leetcode.cn id=1344 lang=cpp
 *
 * [1344] 时钟指针的夹角
 */

// @lc code=start
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleM, angleH;
        angleM = 360.0/60 * minutes;
        if(hour == 12) {
            angleH = 360.0/12 * minutes/60.0;
        } else {
            angleH = 360.0/12 * (hour + minutes/60.0);
        }
        
        // 夹角大于180度时返回劣弧的圆心角，也就是360减去优弧的数值
        double ans = fabsl(angleM - angleH);
        if(ans > 180) {
            return 360-ans;
        } else {
            return ans;
        }
    }
};
// @lc code=end

