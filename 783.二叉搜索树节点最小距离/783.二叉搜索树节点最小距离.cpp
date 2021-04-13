#include "leetcode-definition.h"
#include <bits/stdc++.h>
/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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

priority_queue<int> q;
void visit(TreeNode *root) {
    if(!root) {
        return;
    }
    q.push(root->val);
    visit(root->left);
    visit(root->right);
}

public:
    // 遍历树，将元素存储在优先队列中，然后每次计算优先队列中的最大和第二大值，最小的差值就是整个题的解
    int minDiffInBST(TreeNode* root) {
        visit(root);
        int minDiff = INT_MAX;
        int n1 = q.top();q.pop();
        int n2;
        while(!q.empty()) {
            n2 = q.top(); q.pop();
            minDiff = min(minDiff, abs(n2-n1));
            n1 = n2;
        }
        return minDiff;
    }
};
// @lc code=end

