#include "leetcode-definition.h"
#define INPUT "203.txt"
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0); dummy.next = head;
        ListNode *cur = &dummy;
        while(cur) {
            if(cur->next && cur->next->val == val) {
                cur->next = cur->next->next;
                continue;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end

