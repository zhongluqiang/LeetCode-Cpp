#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans = 0;
        int basic = 0;
        for(int i = 0, len = customers.size(); i < len; i++) {
            if(!grumpy[i]) {
                basic += customers[i];
            }
        }

        int left = 0;
        int right = X-1;
        int temp = basic;
        for(int i = left; i <= right; i++) {
            if(grumpy[i]) {
                temp += customers[i];
            }
        }
        ans = temp;

        while(1) {
            left++, right++;
            if(right == customers.size()) {
                break;
            }
            if(grumpy[left-1]) {
                temp -= customers[left-1];
            }
            if(grumpy[right]) {
                temp += customers[right];
            }
            if(temp > ans) {
                ans = temp;
            }
        }
        return ans;
    }
};
// @lc code=end

