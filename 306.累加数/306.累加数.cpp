#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) return false;
        string s1, s2, tmp;
        long long n1, n2, t;
        for(int i = 0; i < num.size() - 2; i++) {
            tmp.clear();
            s1 = num.substr(0, i+1);
            if(s1.size() > 1 && s1[0] == '0') continue;
            for(int j = i + 1; j < num.size() - 1; j++) {
                s2 = num.substr(i+1, j - i);
                if(s2.size() > 1 && s2[0] == '0') continue;
                n1 = stoll(s1);
                n2 = stoll(s2);
                tmp = s1 + s2;
                while(tmp.size() < num.size()) {
                    tmp += to_string(n1+n2);
                    t = n2;
                    n2 = n1 + n2;
                    n1 = t;
                }
                if(tmp == num) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

