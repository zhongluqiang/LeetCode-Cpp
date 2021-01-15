#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int size = gas.size();
        vector<int> balance(size); // 计算每个节点的结余
        for(int i = 0; i < size; i++) {
            balance[i] = gas[i] - cost[i];
        }
        int cur_balance = 0;  // 记录当前结余，遍历到最后一个结点时，如果结余小于0，表示一定无法环绕一周
        bool trying = false; // 遇到某个balance大于等于0的位置，表示可以尝试一下从这个位置出发
        int cur_pos = 0; // 设置trying为true时顺便记录当前位置
        int cur_gas = 0; // 如果trying为true，则cur_gas记录当前攒了多少升汽油
        for(int i = 0; i < size; i++) {
            cur_balance += balance[i];

            if(!trying) {
                if(balance[i] >= 0) {
                    trying = true;
                    cur_pos = i;
                    cur_gas += balance[i];
                } else {
                    continue;
                }
            } else {
                cur_gas += balance[i];
                if(cur_gas >= 0) {
                    continue;
                } else {
                    trying = false;
                    cur_gas = 0;
                }
            }
        }
        // 遍历完最后一个节点，如果不是trying状态，则可以直接返回-1，否则要看一下总结余是否小于0，只要小于0就无解，否则就有解
        if(!trying) {
            return -1;
        } else {
            if(cur_balance < 0) {
                return -1;
            } else {
                return cur_pos;
            }
        }
    }
};
// @lc code=end

