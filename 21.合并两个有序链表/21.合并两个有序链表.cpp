#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }
        // 确定链表头结束
        ListNode *head = nullptr;
        if(l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        // 比较两个链表，哪个小用哪个
        ListNode *cur = head;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
             cur = cur->next;
        }
        // 剩余的链表直接拼接到尾部
        if(l1) {
            cur->next = l1;
        }
        if(l2) {
            cur->next = l2;
        }
        return head;
    }
};
// @lc code=end

