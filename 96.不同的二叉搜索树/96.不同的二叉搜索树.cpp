#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    /*
    令G(n)为结点1~n构成的二叉搜索树个数，f(i)为以i为根结点的二叉搜索树个数，则：
    G(n) = f(1) + f(2) + f(3) +...+ f(n)
    当i为根结点时，其左子树节点为[1,i-1]，一共有i-1个结点，对应的的二叉搜索树个数是G(i-1)；
    右子树节点为[i+1, n]，一共有n-i个结点，对应的二叉搜索树个数是G(n-1)；
    由此可以得到f(i) = G(i-1)*G(n-i)，即:
    G(n) = G(0)*G(n-1) + G(1)*G(n-2) + G(2)*G(n-3)... + G(n-1)*G(0)
    */
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

