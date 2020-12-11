#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int size = digits.size();
        int carry = 0; // 进位
        
        digits[size-1] += 1;
        if(digits[size-1] == 10) {
            digits[size-1] = 0;
            carry = 1;
        }

        int cur = size - 2;
        while(carry == 1 && cur >= 0) {
            digits[cur] += carry;
            if(digits[cur] == 10) {
                digits[cur] = 0;
                carry = 1;
                cur--;
            } else {
                carry  = 0;
            }
        }

        if(carry != 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

