#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#if 0
class Solution {
    vector<int> ans;
    void inorder(TreeNode *root) {
        if(!root) {
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
public:
    // 前序遍历：中->左->右
    // 中序遍历: 左->中->右
    // 后序遍历: 左->右->中
    // 总结：左子树总是优先右子树，根结点分别为前、中、后
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
#else 
class Solution {
public:
    // 非递归算法，使用栈进行迭代
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        while(cur || !s.empty()) {
            if(cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
#endif
// @lc code=end

