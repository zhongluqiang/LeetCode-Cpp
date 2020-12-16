#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    vector<int> m_data;
    int m_min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        m_data.push_back(x);
        if(m_data.size() == 1) {
            m_min = x;
        } else {
            m_min = min(m_min, x);
        }
    }
    
    void pop() {
        m_data.pop_back();
        m_min = *min_element(m_data.begin(), m_data.end());
    }
    
    int top() {
        return m_data.back();
    }
    
    int getMin() {
        return m_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

