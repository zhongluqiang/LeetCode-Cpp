#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int len = s.size();
        vector<int> v1(s.size()); // v1[i]表示s[0...i]中0的个数
        vector<int> v2(s.size()); // v2[i]表示s[i...n]中1的个数
        int n1 = 0, n2 = 0;

        for(int i = 0; i < len; i++) {
            if(s[i] == '0') {
                n1++;
            }
            v1[i] = n1;
        }
        for(int i = len - 1; i >= 0; i--) {
            if(s[i] == '1') {
                n2++;
            }
            v2[i] = n2;
        }

        // 左右子字符串非空，以i为分割点，计算s[0...i]和s[i+1...n]的分数
        int score = 0;
        for(int i = 0; i < len - 1; i++) {
            score = max(score, v1[i] + v2[i+1]);
        }
        
        return score;
    }
};
// @lc code=end

