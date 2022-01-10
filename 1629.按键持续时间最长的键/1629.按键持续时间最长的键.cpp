#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxtime = 0;
        int cur;

        for(int i = 0; i < releaseTimes.size(); i++) {
            if(i == 0) {
                maxtime = releaseTimes[0];
                cur = keysPressed[0];
            } else {
                if(releaseTimes[i] - releaseTimes[i-1] > maxtime) {
                    maxtime = releaseTimes[i] - releaseTimes[i-1];
                    cur = keysPressed[i];
                } else if(releaseTimes[i] - releaseTimes[i-1] == maxtime) {
                    if(keysPressed[i] > cur) {
                        cur = keysPressed[i];
                    }
                }
            }
        }
        return cur;
    }
};
// @lc code=end

