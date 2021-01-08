#include "leetcode-definition.h"
#define INPUT "86.txt"
/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        // 维护两个链表，一个所有值小于x，一个所有值大于等于x
        // 遍历链表，拆分所有结点到两个链表中，注意使用尾插法，以使元素相对位置保持不变
        // 遍历结束后，将大链表拼接到小链表的尾部，返回小链表头即可
        ListNode headLess(0), headGreater(0);
        ListNode *pLess, *pGreater;
        headLess.next = headGreater.next = nullptr;
        pLess = &headLess;
        pGreater = &headGreater;

        while(head) {
            if(head->val < x) {
                pLess->next = head;
                pLess = pLess->next;
            } else {
                pGreater->next = head;
                pGreater = pGreater->next;
            }
            head = head->next;
        }
        pGreater->next = nullptr;
        pLess->next = headGreater.next;
        return headLess.next;
    }
};
// @lc code=end

