#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
#if 0
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
#endif

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* copyRandomList(Node* head) {
        if(!head) { return head; }
        if(visited.find(head) != visited.end()) {
            return visited[head];
        }
        Node* cloneHead = new Node(head->val);
        visited[head] = cloneHead;
        cloneHead->next = copyRandomList(head->next);
        cloneHead->random = copyRandomList(head->random);
        return cloneHead;
    }
};
// @lc code=end

