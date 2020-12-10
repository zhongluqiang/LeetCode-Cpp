#include <bits/stdc++.h>
using namespace std;
#define INPUT "5550.txt"
/*
 * @lc app=leetcode.cn id=5550 lang=cpp
 *
 * [5550] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int size = code.size();
        vector<int> ans(size, 0);

        if(k == 0) {
            return ans;
        }

        if(k > 0) {
            for(int i = 0; i < size; i++) {
                for(int j = 1; j <= k; j++) {
                    ans[i] += code[(i+j)%size];
                }
            }
        }

        if(k < 0) {
            k = abs(k);
            for(int i = 0; i < size; i++) {
                for(int j = 1; j <= k; j++) {
                    ans[i] += code[(i-j+size)%size];
                }
            }
        }

        return ans;
    }
};
// @lc code=end

