/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */

// @lc code=start
class Solution {

inline int pow(int base, int exp) {
    int ans = 1;
    for(int i = 0; i < exp; i++) {
        ans *= base;
    }
    return ans;
}

public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets <= 1) {
            return 0;
        }
        // 1只猪喝4次水可以检验出5个水桶中哪个是有毒的
        // 2只猪喝4次水可以检验出25个水桶中哪个有毒
        // 以此类推，3只猪可以检验的是125...
        int base = minutesToTest / minutesToDie + 1;

        int ans = 1;
        while(pow(base, ans) < buckets) {
            ans++;
        }
        
        return ans;
    }
};
// @lc code=end

