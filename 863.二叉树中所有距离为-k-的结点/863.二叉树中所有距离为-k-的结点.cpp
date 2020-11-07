#include "leetcode-definition.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#if 0
class Solution {
    // 基于unordered_map构建无向图,key是当前结点,value是邻结点的集合，使用vector表示
    unordered_map<TreeNode *, vector<TreeNode*>> g;

    //递归构建无向图
    void buildGraph(TreeNode *parent, TreeNode *child) {
        if(parent) {
            g[parent].push_back(child);
            g[child].push_back(parent);
        }
        if(child->left) buildGraph(child, child->left);
        if(child->right) buildGraph(child, child->right);
    }   
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(nullptr, root);      // 构建无向图
        vector<int> ans;                // 存储遍历结果
        unordered_set<TreeNode*> seen;  // 存储哪些结果遍历过了
        int k = 0;                      // 当前遍历到第几步
        queue<TreeNode*> q;             // 用于BFS

        seen.insert(target);
        q.push(target);
        while(!q.empty() && k <= K) {
            // BFS遍历，每次遍历一层结点
            int s = q.size();
            while(s--) {
                TreeNode *node = q.front();
                q.pop();
                if(k == K) {
                    ans.push_back(node->val);
                }
                for(TreeNode *child : g[node]) {
                    if(seen.count(child)) {
                        continue;
                    }
                    q.push(child);
                    seen.insert(child);
                }
            }
            ++k;
        }
        return ans;
    }
};
#else
class Solution {
    vector<int> ans;

    // 收集与root结点距离为d的所有结点
    void collect(TreeNode *root, int d) {
        if(!root) {
            return;
        }
        if(d == 0) {
            ans.push_back(root->val);
        }
        collect(root->left, d-1);
        collect(root->right, d-1);
    }

    // 递归收集root树中所有与target距离为k的结点，并返回与target的距离，如果距离为-1，表示target不在root树中
    int distance(TreeNode *root, TreeNode *target, int k) {
        if(!root) {
            return -1;
        }
        if(root == target) {
            collect(target, k);
            return 0;
        }

        // 计算左右子树与target的距离
        int l = distance(root->left, target, k);
        int r = distance(root->right, target, k);

        // target在root左子树中
        if(l >= 0) {
            // 左子树与target距离为k-1，说明根结点与target距离刚好为k
            if(l == k-1) {
                ans.push_back(root->val);
            }
            // 在右子树中收集与target距离为k-l-2的结点
            collect(root->right, k-l-2);
            return l + 1;
        }

        // target在root右子树中
        if(r >= 0) {
            if(r == k-1) {
                ans.push_back(root->val);
            }
            collect(root->left, k-r-2);
            return r + 1;
        }
        return -1;
    } // end distance

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        ans.clear();
        distance(root, target, K);
        return ans;
    } //end distanceK
};
#endif
// @lc code=end

