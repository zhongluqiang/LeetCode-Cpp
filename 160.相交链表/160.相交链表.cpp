/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            return nullptr;
        }
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while(p1 != p2) {
            p1 = (p1 == nullptr ? headB : p1->next);
            p2 = (p2 == nullptr ? headA : p2->next);
        }
        return p1;
    }
};
// @lc code=end

