#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "649.txt"
/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    // 保证每次都干掉下一轮离自己最近的对手就可以保证最已方最大优势，直到已方人数超过对方的两倍即可
    string predictPartyVictory(string senate) {
        char opponent['R'+1];
        opponent['R'] = 'D';
        opponent['D'] = 'R';
        const int size = senate.size();
        int rs = 0;
        int ds = 0;
        for(auto &ch : senate) {
            ch == 'R' ? ++rs : ++ds;
        }
        while(1) {
            if(rs > ds*2 || ds > 2*rs) {
                    break;
            }
            for(int i = 0; i < size; i++) {
                if(senate[i] == 'x') {
                    continue;
                }
                int j = i+1;
                while(senate[j%size] != opponent[senate[i]]) {
                    j++;
                }
                if(senate[j%size] == 'R') {
                    rs--;
                } else {
                    ds--;
                }
                if(rs > ds*2 || ds > 2*rs) {
                    break;
                }
                senate[j%size] = 'x';
            }
        }
        if(rs > ds*2) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};
// @lc code=end

