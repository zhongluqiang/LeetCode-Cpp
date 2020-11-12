#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "6.txt"
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }

        string line[numRows];
        int length = s.length();
        int loopsize = numRows + numRows - 2;

        for(int i = 0; i < length; i += loopsize) {
            int start = i;
            for(int j = 0; j < numRows && start + j < length; j++) {
                line[j] += s[start+j];
            }
            for(int j = 0; j < numRows-2 && start + numRows + j < length; j++) {
                line[numRows-2-j] += s[start+numRows+j];
            }
        }
        string ans;
        for(int i = 0; i < numRows; i++) {
            ans += line[i];
        }
        return ans;
    }
};
// @lc code=end

