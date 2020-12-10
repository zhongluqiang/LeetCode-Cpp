#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "860.txt"
/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changes[21] = {0}; // changes[5]、changes[10]、changes[20]分别表示三种零钱的数目

        for(int bill : bills) {
            changes[bill]++;
            int change = bill - 5;
            if(change == 0) {
                continue;
            }
            // 只有可能找零5块和15块，找零时尽量先使用大额面值的零钱可以保证最优解
            if(change == 5) {
                if(changes[5] == 0) {
                    return false;
                } else {
                    changes[5]--;
                }
            } else if(change == 15) {
                if(changes[10] > 0) {
                    changes[10]--;
                    change = 5;
                }
                if(changes[5] < change/5) {
                    return false;
                } else {
                    changes[5] -= change/5;
                }
            } else {
                // not possible
            }
        }

        return true;
    }
};
// @lc code=end

