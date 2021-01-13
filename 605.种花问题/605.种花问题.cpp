#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int size = flowerbed.size();
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int ans = 0;
        for(int i = 1; i <= size; i++) {
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                ans++;
            }
        }
        return ans >= n;
    }
};
// @lc code=end

