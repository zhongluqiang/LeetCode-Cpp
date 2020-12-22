#include "leetcode-definition.h"
#define INPUT "2.txt"
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        ListNode *ans = nullptr;
        ListNode *tail = nullptr;
        int carry = 0;

        while(l1 && l2) {
            int n = l1->val + l2->val + carry;
            if(n >= 10) {
                n -= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            ListNode *node = new ListNode(n);
            if(!ans) {
                ans = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1) {
            while(l1) {
                int n = l1->val + carry;
                if(n >= 10) {
                    n -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                ListNode *node = new ListNode(n);
                tail->next = node;
                tail = node;
                l1 = l1->next;
            }
        }
        if(l2) {
            while(l2) {
                int n = l2->val + carry;
                if(n >= 10) {
                    n -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                ListNode *node = new ListNode(n);
                tail->next = node;
                tail = node;
                l2 = l2->next;
            }
        }
        if(carry) {
            ListNode *node = new ListNode(1);
            tail->next = node;
            tail = node;
        }

        return ans;
    } // end addTwoNumbers
};
// @lc code=end

