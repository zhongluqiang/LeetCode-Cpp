#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    // 快慢指针法，快指针先走n步，再快慢指针一起走，等到快指针指向最后一个元素时，慢指针指向的就是倒数第n个元素的前一个元素
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // 快指针直接走到了尾部，说明头结点就是倒数第n个元素
        if(!fast) {
            return head->next;
        }

        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
// @lc code=end

