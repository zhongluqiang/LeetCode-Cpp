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
    string predictPartyVictory(string senate) {
        const int size = senate.size();
        
        // 用两个队列存储天辉和夜魇的索引
        queue<int> ra, di;
        for(int i = 0; i < size; i++) {
            if(senate[i] == 'R') {
                ra.push(i);
            } else {
                di.push(i);
            }
        }

        // 两个队列同时出队，索引靠前的再回队，靠后的不回队，表示靠后的被靠前的干掉了
        while(1) {
            if(ra.size() > di.size()*2 || di.size() > ra.size()*2) {
                break;
            }
            int raIdx = ra.front(); ra.pop();
            int diIdx = di.front(); di.pop();
            if(raIdx < diIdx) {
                ra.push(raIdx+size); // 重新回队的时候位置加上size，表示下一轮循环的位置
            } else {
                di.push(diIdx+size);
            }
        }

        if(ra.size() > di.size()*2) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};
// @lc code=end

