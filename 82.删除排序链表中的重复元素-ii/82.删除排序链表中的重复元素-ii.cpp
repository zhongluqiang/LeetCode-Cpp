#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
class Solution {
    ListNode* deleteDuplicatesByRecursion(ListNode *head, int target) {
        if(!head || !head->next ) { return head; }
        if(head->next->val != target) {
            head->next = deleteDuplicatesByRecursion(head->next, head->next->val);
            return head;
        } else {
            while(head && head->val == target) {
                head = head->next;
            }
            if(head && head->next) {
                return deleteDuplicatesByRecursion(head, head->val);
            } else {
                return head;
            }
            
        }
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) { return head; }
        
        return deleteDuplicatesByRecursion(head, head->val);
    }
};
// @lc code=end

