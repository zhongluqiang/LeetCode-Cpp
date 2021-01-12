#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
class Solution {
    inline bool validate(TreeNode *root, long min, long max) {
        if(!root) {
            return true;
        }
        if(root->val <= min || root->val >= max) {
            return false;
        }
        // 左子树所有结点都小于根结点，右子树所有结点都大于根结点
        return validate(root->left, min, root->val)
                && validate(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, INT64_MIN, INT64_MAX);
    }
};
// @lc code=end

