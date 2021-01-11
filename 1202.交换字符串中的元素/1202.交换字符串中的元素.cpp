#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "1202.txt"
/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class Solution {
    class DSU{
    private:
        //vector<int> parent_;
        int parent_[100010];
    public:
        DSU(int n) {
            for(int i = 0; i < n; i++) {
                parent_[i] = i;
            }
        }
        void merge(int x, int y) {
            parent_[find(x)] = find(y); //将x的parent设置成y的parent
        }
        int find(int x) {
            if(parent_[x] != x) {
                return find(parent_[x]);
            }
            return parent_[x];
        }
    };
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int size = s.size();
        DSU dsu(size);
        for(const auto &p : pairs) {
            dsu.merge(p[0], p[1]);
        }
        
        int parent[100010]; // parent[i]表示i所在的分组
        for(int i = 0; i < size; i++) {
            parent[i] = dsu.find(i);
        }

        unordered_map<int, priority_queue<int>> groups; // groups[i]表示同一个分组下的所有字符
        for(int i = 0; i < size; i++) {
            //groups[dsu.find(i)].push(-s[i]);
            groups[parent[i]].push(-s[i]);
        }
        string ans;
        for(int i = 0; i < size; i++) {
            //int g = dsu.find(i);
            int g = parent[i];
            ans.push_back(-groups[g].top());
            groups[g].pop();
        }
        return ans; 
    }
};
// @lc code=end

