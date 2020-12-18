/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    // 统计5的因子数
    int trailingZeroes(int n) {
        int ans = 0;
        while(n > 0) {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
};
// @lc code=end

