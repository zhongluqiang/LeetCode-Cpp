#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> cur_level;
            int size = q.size();
            while(size > 0) {
                auto t = q.front(); q.pop();
                size--;
                cur_level.push_back(t->val);
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
            ans.insert(ans.begin(), cur_level);
        }

        return ans;
    }
};
// @lc code=end

