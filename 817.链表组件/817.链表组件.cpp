#include "leetcode-definition.h"
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define INPUT "817.txt"
/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#if 0
class Solution {
    void dfs(int cur, unordered_map<int, vector<int>> &g, unordered_set<int> &visited) {
        if(visited.count(cur)) {
            return;
        }
        visited.insert(cur);
        for(const int next : g[cur]) {
            dfs(next, g, visited);
        }
    }
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> f(G.begin(), G.end());
        unordered_map<int, vector<int>> g;

        int u = head->val;
        while(head->next) {
            head = head->next;
            int v = head->val;
            if(f.count(u) && f.count(v)) {
                g[u].push_back(v);
                g[v].push_back(u);
            }
            u = v;
        }
        
        int ans = 0;
        unordered_set<int> visited;
        for(int u : G) {
            if(visited.count(u)) continue;
            ++ans;
            dfs(u, g, visited);
        }
        return ans;
    } // end numComponents
};
#else
class Solution {
   
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> g(G.begin(), G.end());
        int ans = 0;
        while(head) {
            if(g.count(head->val) && (!head->next || !g.count(head->next->val))) {
                ans++;
            }
            head = head->next;
        }
        return ans;
    }
};
#endif
// @lc code=end

