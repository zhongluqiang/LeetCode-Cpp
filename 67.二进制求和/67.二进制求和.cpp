#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int p1 = a.size() - 1;
        int p2 = b.size() - 1;

        int tmp;
        while(p1 >= 0 && p2 >= 0) {
            tmp = a[p1]-'0' + b[p2]-'0' + carry;
            if(tmp >= 2) {
                tmp -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.insert(ans.begin(), tmp+'0');
            p1--;
            p2--;
        }
        while(p1 >= 0) {
            tmp = a[p1]-'0' + carry;
            if(tmp >= 2) {
                tmp -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.insert(ans.begin(), tmp+'0');
            p1--;
        }

        while(p2 >= 0) {
            tmp = b[p2]-'0' + carry;
            if(tmp >= 2) {
                tmp -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.insert(ans.begin(), tmp+'0');
            p2--;
        }
        if(carry > 0) {
            ans.insert(ans.begin(), '1');
        }
        return ans;
    }
};
// @lc code=end

