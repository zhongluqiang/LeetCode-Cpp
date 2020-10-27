#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;
#define INPUT "1024.txt"
/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        // maxr[i]保存i点最多能向右延伸到哪个位置
        vector<int> maxr(101);

        // 遍历所有区间，对区间内出现过的点，计算向右能延伸的最大长度，如果没出现，那么这个位置的值是0
        for(auto &c : clips) {
            for(int i = c[0]; i <= c[1]; i++) {
                maxr[i] = max(maxr[i], c[1]);
            }
        }

        int cur = 0, ans = 0;
        while(cur < T) {
            if(maxr[cur] == 0 || maxr[cur] == cur) { // 从某个点无法向右延伸或最多只能延伸到自己的位置，因为这个位置又不是终点，所以无解
                return -1;
            }
            cur = maxr[cur]; // 将当前点移动到最右能延伸到的点，能伸展几次，就说明需要多少个区间
            ans++;
        }
        return ans;
    } //end videoStitching
};
// @lc code=end

