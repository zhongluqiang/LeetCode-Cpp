#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
#if 0
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
#endif

class Solution {
public:
    unordered_map<Node*, Node*> visited; // visited[i]表示i节点的克隆节点
    Node* cloneGraph(Node* node) {
        if(!node) { return node; }

        // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
        if(visited.find(node) != visited.end()) {
            return visited[node];
        }
        // 深拷贝，记录原结点和克隆节点的对应关系
        Node *cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for(auto &neighbor : node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};
// @lc code=end

