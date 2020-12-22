#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int order = 0; // 0: 从左往右， 1：从右往左

        // 层次遍历，根据当前顺序决定是否对遍历结果进行反向，每层遍历完后顺序取反
        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            while(size-- > 0) {
                auto node = q.front(); q.pop();
                v.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }

            if(order == 0) {
                ans.push_back(v);
            } else {
                ans.push_back({v.rbegin(), v.rend()});
            }
            
            order = !order;
        }
        
        return ans;
    } // end zigzagLevelOrder
};
// @lc code=end

