#include "leetcode-definition.h"
#define INPUT "83.txt"
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) {
            return head;
        }

        auto cur = head;
        auto next = cur->next;
        while(next) {
            while(next && next->val == cur->val) {
                auto tmp = next;
                cur->next = tmp->next;
                next = tmp->next;
                delete tmp;
            }
            cur = next;
            if(cur) {
                next = cur->next;
            } else {
                next = nullptr;
            }
        }
        return head;
    }
};
// @lc code=end

