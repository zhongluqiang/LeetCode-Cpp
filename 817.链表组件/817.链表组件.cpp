#include "leetcode-definition.h"
#include <unordered_map>
using namespace std;
#define INPUT "817.txt"
/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode* head, vector<int>& G) {
        int ans = 0;
        ListNode *node;
        unordered_map<int, int> indexG;
        unordered_map<int, ListNode*> indexNode;

        // 因为链表值是唯一的，这里对链表和输入数组建立反向索引，便于根据值引用到链表结点，
        // 以及快速递归某个值是否在输入数组G中
        for(int i = 0; i < G.size(); i++) {
            indexG[G[i]] = i;
        }

        for(node = head; node != nullptr; node = node->next) {
            indexNode[node->val] = node;
        }

        // 遍历链表结点，判断结点的值是否存在数组G中，如果存，则遍历该结点后面连续出现在数组G中的结点，
        // 直到结点的值不在数组G中为止，每遍历一个值，就是数组G中把这个值删除，最后再删除起点的值，结果加1
        node = head;
        while(node != nullptr) {
            int val = node->val;
            if(indexG.find(val) != indexG.end()){
                while(node->next && indexG.find(node->next->val) != indexG.end()) {
                    indexG.erase(node->next->val);
                    node = node->next;
                }
                indexG.erase(val);
                ans++;
            } else {
                node = node->next;
            }
        }

        return ans;
    }
};
// @lc code=end

