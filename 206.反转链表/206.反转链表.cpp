#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) { return head; }
        ListNode *new_head = nullptr;
        ListNode *cur;
        ListNode *tmp;

        cur = head;
        while(cur) {
            tmp = cur->next;
            cur->next = new_head;
            new_head = cur;
            cur = tmp;
        }
        return new_head;
    }
};
// @lc code=end

