#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode dummy(0); dummy.next = head;
        ListNode *p1, *p2, *p3, *p4;
        p1 = &dummy;
        
        while(p1->next) {
            p2 = p1->next;
            p3 = p2->next;
            if(!p3) {
                break;
            }
            p4 = p3->next;
            p1->next = p3;
            p3->next = p2;
            p2->next = p4;
            p1 = p2;
            
        }
        return dummy.next;
    } // end swapPairs
};
// @lc code=end

