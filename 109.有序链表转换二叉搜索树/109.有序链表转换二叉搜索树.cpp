#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *generate(const vector<int> &nums, int start, int end) {
        if(start > end) {
            return nullptr;
        }
        int mid = start + (end-start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = generate(nums, start, mid-1);
        root->right = generate(nums, mid+1, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) { return nullptr; }
        vector<int> nums;
        ListNode *cur = head;
        while(cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        return generate(nums, 0, nums.size()-1);
    }
};
// @lc code=end

