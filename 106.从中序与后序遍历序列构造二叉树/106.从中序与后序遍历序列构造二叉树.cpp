#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *post_order(int postorderLeft, int postorderRight
                         , int inorderLeft, int inorderRight
                         , vector<int> &post, vector<int> &in) {
        if(postorderLeft > postorderRight || inorderLeft > inorderRight) {
            return nullptr;
        }
        // 后序遍历的最后一个结点就是当前树的根结点
        TreeNode *root = new TreeNode(post[postorderRight]);
        // 找出根结点在中序遍历中的位置
        int rootPos = inorderLeft;
        while(rootPos <= inorderRight && in[rootPos] != post[postorderRight]) {
            rootPos++;
        }
        // 计算右子树的长度
        int rightLen = inorderRight - rootPos;
        // 递归计算左右子树
        // 左子树：root->left = post_order(后序左子树范围，中序左子树范围，后序序列，中序序列);
        // 右子树：root->right = post_order(后序右子树范围，中序右子树范围，后序序列，中序序列);
        root->left = post_order(postorderLeft, postorderRight-rightLen-1, inorderLeft, rootPos-1, post, in);
        root->right = post_order(postorderRight-rightLen, postorderRight-1, rootPos+1, inorderRight, post, in);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return post_order(0, inorder.size()-1, 0, inorder.size()-1, postorder, inorder);
    }
};
// @lc code=end

