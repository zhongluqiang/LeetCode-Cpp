#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#if 0 
// 位运算+状态转移
// 参考：https://leetcode-cn.com/problems/single-number-ii/solution/zi-dong-ji-wei-yun-suan-zui-xiang-xi-de-tui-dao-gu/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for(auto x : nums) {
            once = (once ^ x) & (~twice);
            twice = (twice ^x) & (~once); 
        }
        return once;
    }
};
#else 
// 统计每个bit位出现次数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(auto x : nums) {
                cnt += (x >> i) & 0x1;
            }
            ans |= (cnt % 3) << i;  // cnt%3只有可能是0或1
        }
        return ans;
    }
};
#endif
// @lc code=end

