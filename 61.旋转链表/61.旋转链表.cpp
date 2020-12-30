#include "leetcode-definition.h"
#define INPUT "61.txt"
/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) { return head; }
        int count = 1;
        auto p = head;
        while(p->next) {
            p = p->next;
            count++;
        }
        k = k % count;
        k = count - k;
        p->next = head;
        while(k-- > 0) {
            p = p->next;
        }
        auto tmp = p->next;
        p->next = nullptr;
        return tmp;
    }
};
// @lc code=end

