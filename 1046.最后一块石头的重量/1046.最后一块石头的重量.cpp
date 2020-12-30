#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q; // 最大堆
        for(auto i : stones) {
            q.push(i);
        }
        int n1, n2;
        while(q.size() >= 2) {
            n1 = q.top(); q.pop();
            n2 = q.top(); q.pop();
            if(abs(n1-n2) != 0) {
                q.push(abs(n1-n2));
            }
        }
        if(q.empty()) {
            return 0;
        } else {
            return q.top();
        }
    } // end lastStoneWeight
};
// @lc code=end

