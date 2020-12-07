#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "1103.txt"
/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int t = 0; // 重复第几轮
        while (candies > 0) {
            int base = t*num_people + 1; // 每轮发糖的基数
            for(int i = 0; i < num_people; i++) {
                if(candies > i+base) {
                    ans[i] += i+base;
                    candies -= i+base;
                } else {
                    ans[i] += candies;
                    candies = 0;
                    break;
                }
            }
            t++;
        }

        return ans;
    }
};
// @lc code=end

