#include "leetcode-definition.h"
#define INPUT "113.txt"
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ans;
    int g_sum;
    void bfs(TreeNode *root, vector<int> &temp, int sum) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right && sum+root->val == g_sum) {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        } 
        temp.push_back(root->val);
        if(root->left) {
            bfs(root->left, temp, sum+root->val);
        }
        if(root->right) {
            bfs(root->right, temp, sum+root->val);
        }
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        g_sum = sum;
        vector<int> temp;
        bfs(root, temp, 0);
        return ans;
    }
};
// @lc code=end

