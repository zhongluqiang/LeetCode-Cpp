#include "leetcode-definition.h"
#define INPUT "101.txt"
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool RecursiveIsSymmetric(TreeNode *left, TreeNode *right) {
        if(!left && !right) {
            return true;
        } else if(left && right && left->val == right->val) {
            return RecursiveIsSymmetric(left->left, right->right) && RecursiveIsSymmetric(left->right, right->left);
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }
        return RecursiveIsSymmetric(root->left, root->right);
    }
};
// @lc code=end

