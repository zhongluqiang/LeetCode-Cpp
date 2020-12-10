#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=5601 lang=cpp
 *
 * [5601] 设计有序流
 */

// @lc code=start
class OrderedStream {
    int ptr;
    vector<string> data;
public:
    OrderedStream(int n)
    : data(n+1) {
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        data[id] = value;
        
        if(ptr == data.size()) {
            return {};
        }

        vector<string> ans;
        while(ptr < data.size() && data[ptr].size() > 0) {
            ans.push_back(data[ptr]);
            ptr++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
// @lc code=end

