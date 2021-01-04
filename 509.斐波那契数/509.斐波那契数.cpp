#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
    vector<int> f;
    inline int fibonacci(int n) {
        if(n == 0 || n == 1) { return n; }
        if(f[n]) { return f[n];}
        f[n] = fibonacci(n-1) + fibonacci(n-2);
        return f[n];
    }
public:
    int fib(int n) {
        f.resize(n+1, 0);
        return fibonacci(n);
    }
};
// @lc code=end

