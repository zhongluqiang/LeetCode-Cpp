#include "leetcode-definition.h"
#define INPUT "204.txt"
/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) { return 0; }
        vector<bool> flag(n, true);
        flag[0] = flag[1] = false; // 排除0和1
        for(int i = 2, upperbound = sqrt(n); i <= upperbound; i++) {
            if(flag[i]) {
                for(int j = i*i; j <= n; j+= i) {
                    flag[j] = false;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(flag[i]) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

