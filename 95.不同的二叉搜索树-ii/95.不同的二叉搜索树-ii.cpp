#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generate(int start, int end) {
        if(start > end) {
            return {nullptr};
        }
        vector<TreeNode*> ans;
        // 枚举所有根结点
        for(int i = start; i <= end; i++) {
            // 获取所有可行的左子树集合，左子树的区间为(start, i-1)
            vector<TreeNode*> leftTrees = generate(start, i-1);
            // 获取所有可行的右子树集合，右子树的区间为(i+1, end)
            vector<TreeNode*> rightTrees = generate(i+1, end);
            // 左子树选一个，右子树选一个，拼接到根结点上
            for(auto &left : leftTrees) {
                for(auto &right : rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n) {
            return {};
        }
        return generate(1, n);
    }
};
// @lc code=end

