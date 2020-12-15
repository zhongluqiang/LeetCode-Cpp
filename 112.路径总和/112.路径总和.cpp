#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
public:
    // 层次遍历+求和，遇到没有叶子结点的结点时判断当前结点的和与目标sum是否相同即可
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) {
            return false;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                auto node = q.front(); q.pop();
                size--;
                if(!node->left && !node->right) {
                    if(node->val == sum) {
                        return true;
                    }
                }
                if(node->left) {
                    node->left->val += node->val;
                    q.push(node->left);
                }
                if(node->right) {
                    node->right->val += node->val;
                    q.push(node->right);
                }
            }
        }
        return false;
    }
};
// @lc code=end

