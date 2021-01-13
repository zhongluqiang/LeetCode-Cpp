#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int ans;
    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            ans += root->val;
            return;
        }
        if(root->left) {
            root->left->val += root->val * 10;
            dfs(root->left);
        }
        if(root->right) {
            root->right->val += root->val * 10;
            dfs(root->right);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

