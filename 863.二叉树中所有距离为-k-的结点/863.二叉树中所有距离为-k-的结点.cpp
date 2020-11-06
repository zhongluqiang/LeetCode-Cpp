#include "leetcode-definition.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // 基于unordered_map构建无向图,key是当前结点,value是邻结点的集合，使用vector表示
    unordered_map<TreeNode *, vector<TreeNode*>> g;

    //递归构建无向图
    void buildGraph(TreeNode *parent, TreeNode *child) {
        if(parent) {
            g[parent].push_back(child);
            g[child].push_back(parent);
        }
        if(child->left) buildGraph(child, child->left);
        if(child->right) buildGraph(child, child->right);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(nullptr, root);      // 构建无向图
        vector<int> ans;                // 存储遍历结果
        unordered_set<TreeNode*> seen;  // 存储哪些结果遍历过了
        int k = 0;                      // 当前遍历到第几步
        queue<TreeNode*> q;             // 用于BFS

        seen.insert(target);
        q.push(target);
        while(!q.empty() && k <= K) {
            // BFS遍历，每次遍历一层结点
            int s = q.size();
            while(s--) {
                TreeNode *node = q.front();
                q.pop();
                if(k == K) {
                    ans.push_back(node->val);
                }
                for(TreeNode *child : g[node]) {
                    if(seen.count(child)) {
                        continue;
                    }
                    q.push(child);
                    seen.insert(child);
                }
            }
            ++k;
        }
        return ans;
    }
};
// @lc code=end

