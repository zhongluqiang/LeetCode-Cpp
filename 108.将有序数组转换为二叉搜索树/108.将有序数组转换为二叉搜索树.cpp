#include "leetcode-definition.h"
#define INPUT "108.txt"
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int size = nums.size();
        if(size == 0) {
            return nullptr;
        } else if(size == 1) {
            TreeNode *node = new TreeNode(nums[0]);
            return node;
        } else {
            TreeNode *node = new TreeNode(nums[size/2]);
            vector<int> left(nums.begin(), nums.begin()+size/2);
            vector<int> right(nums.begin()+size/2+1, nums.end());
            node->left = sortedArrayToBST(left);
            node->right = sortedArrayToBST(right);
            return node;
        }
    }
};
// @lc code=end

