#include "leetcode-definition.h"
#define INPUT "230.txt"
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
public:
    int gk;
    int kth;
    void inOrder(TreeNode *root) {
        if(!root) {
            return;
        }
        inOrder(root->left);
        if(gk == 0) {
            return;
        }
        kth = root->val;
        gk--;
        inOrder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        gk = k;
        inOrder(root);
        return kth;
    }
};
// @lc code=end

