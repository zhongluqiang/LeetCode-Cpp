#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    // 层次遍历，遇到第一个没有叶子结点的结点时结束遍历并返回当前遍历到第几层即可
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            ans++;
            int size = q.size();
            while(size > 0) {
                auto node = q.front(); q.pop();
                size--;
                if(!node->left && !node->right) {
                    return ans;
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

