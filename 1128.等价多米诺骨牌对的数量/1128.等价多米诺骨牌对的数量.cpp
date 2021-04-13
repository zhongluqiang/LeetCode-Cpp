#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "1128.txt"
/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        int count[10][10] = {0};
        for(auto &v : dominoes) {
            int a = v[0];
            int b = v[1];
            count[a][b]++;
            if(a != b) {
                count[b][a]++;
            }
        }
        for(int i = 1; i <= 9; i++) {
            for(int j = i; j <= 9; j++) {
                ans += count[i][j] * (count[i][j]-1) / 2;
            }
        }
        return ans;
    }
};
// @lc code=end

