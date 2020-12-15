#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    inline bool isBlancedByDepth(TreeNode *root, int *depth) {
        if(!root) {
            *depth = 0;
            return true;
        }

        int leftDepth, rightDepth;
        bool bLeft = isBlancedByDepth(root->left, &leftDepth);
        bool bRight = isBlancedByDepth(root->right, &rightDepth);

        if(bLeft && bRight) {
            if(abs(leftDepth - rightDepth) <= 1) {
                *depth = max(leftDepth, rightDepth) + 1;
                return true;
            }
        }
        return false;
    }

public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBlancedByDepth(root, &depth);
    }
};
// @lc code=end

