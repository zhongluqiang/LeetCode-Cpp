#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "738.txt"
/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
    string monotoneIncreasingDigitsString(string str) {
        if(str.empty()) {
            return "";
        }

        // 找出str的第一个非单调数字的位置，只有1位的数字一定是单调的，所以这个数字肯定是从第2位开始的
        int k;
        for(k = 1; k < str.size(); k++) {
            if(str[k] < str[k-1]) {
                break;
            }
        }

        if(k == str.size()) {
            // 没有非单调的数字，也就是str本身就是单调的，直接返回str即可
            return str;
        }

        // 将k及k以后的字符都变成9
        for(int i = k; i < str.size(); i++) {
            str[i] = '9';
        }

        // k前面的数字减1，由于k是从第2位开始的，所以必然存在k前面的数字，并且k前面的数字不可能是0，所以下面的语句总是合法的
        str[k-1]--;

        // 递归处理k前面的数字再加上k及k以后的数字就是最终结果
        return monotoneIncreasingDigitsString(str.substr(0, k)) + str.substr(k);
    }
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        return stoi(monotoneIncreasingDigitsString(strN));
    }
};
// @lc code=end

