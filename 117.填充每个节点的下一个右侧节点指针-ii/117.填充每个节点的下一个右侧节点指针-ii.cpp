#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start

// Definition for a Node.
#if 0
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
#endif 

#if 0
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return root;
        }
        queue<Node *> q;
        Node *node;
        queue<Node *> q2;
        
        q.push(root);
        while(!q.empty()) {
            node = q.front(); q.pop();
            if(!q.empty()) {
                node->next = q.front();
            } else {
                node->next = nullptr;
            }
            if(node->left) {
                q2.push(node->left);
            }
            if(node->right) {
                q2.push(node->right);
            }
            if(q.empty()) {
                while(!q2.empty()) {
                    q.push(q2.front());
                    q2.pop();
                }
            }
        }
        return root;
    } // end connect
};
#else 
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return root;
        }
        Node *cur = root;
        while(cur != nullptr) {
            Node dummy = Node(0); // 用一个头节点标注下一层链表的起始位置
            Node *pre = &dummy; 
            while(cur) {
                if(cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if(cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = dummy.next;
        }
        return root;
    }
};
#endif
// @lc code=end

