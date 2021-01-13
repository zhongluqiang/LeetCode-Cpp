#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *pre_order(int preorder_left, int preorder_right
                        , int inorder_left, int inorder_right
                        , vector<int> &pre, vector<int> &in) {
        if(preorder_left > preorder_right || inorder_left > inorder_right) {
            return nullptr;
        }
        // 前序遍历的第一个结点就是当前树的根结点
        TreeNode *root = new TreeNode(pre[preorder_left]); 
        // 找出前序遍历的第一个结点、也就是当前的根结点在中序遍历的位置
        int root_pos = inorder_left;
        while(root_pos <= inorder_right && in[root_pos] != pre[preorder_left]) {
            root_pos++;
        }
        // 计算左子树的区间长度
        int left_len = root_pos - inorder_left;
        // 递归计算左子树，右子树
        // 左子树：root->left = pre_order(前序左子树范围，中序左子树范围，前序序列，中序序列)
        // 右子树：root->right = pre_order(前序右子树范围，中序右子树范围，前序序列，中序序列)
        root->left = pre_order(preorder_left+1, preorder_left+left_len, inorder_left, root_pos-1, pre, in);
        root->right = pre_order(preorder_left+left_len+1, preorder_right, root_pos+1, inorder_right, pre, in);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int size = preorder.size();
        return pre_order(0, size-1, 0, size-1, preorder, inorder); 
    }
};
// @lc code=end

