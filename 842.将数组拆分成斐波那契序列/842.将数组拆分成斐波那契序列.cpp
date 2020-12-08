#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "842.txt"
/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 */

// @lc code=start
class Solution {
    // 以s[0,a)和s[a,b)为前2个元素构造斐波那契序列，看是否能够构造成功，如果成功，返回
    // 对应的斐波那契序列，否则返回空的vector
    vector<int> fibonacci(const string &s, int a, int b) {
        string s1 = s.substr(0, a);
        string s2 = s.substr(a, b-a);
        //cout << "s1:" << s1 << ", s2:" << s2 << endl;

        vector<int> ans;
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        
        int offset = s1.length() + s2.length();
        if(offset >= s.size()) {
            return {};
        }

        ans.push_back(n1);
        ans.push_back(n2);
        while(offset < s.size()) {
            long long n3 = (long long)n1 + (long long)n2;
            if(n3 > INT_MAX) {
                return {};
            }
            string s3 = to_string(n3);
            if(s.find(s3, offset) != offset) {
               return {};
            }
            ans.push_back(static_cast<int>(n3));
            offset += s3.length();
            n1 = n2;
            n2 = static_cast<int>(n3);
        }
        return ans;
    }
public:
    // 枚举所有可能的第1个元素和第2个元素，看能否构成斐波那契序列
    vector<int> splitIntoFibonacci(string S) {
        const int size = S.length();
        if(size < 3) {
            return {};
        }

        vector<int> ans;
        
        // 第1个字符为0时，只能以0作为序列的第1个元素
        if(S[0] == '0') {
            for(int i = 2; i < size; i++) {
                // 限制第2个元素不能超过INT上限
                if(stoll(S.substr(1, i)) > INT_MAX) {
                    break;
                }
                ans = fibonacci(S, 1, i);
                if(ans.size() >= 3) {
                    return ans;
                }
            }
        } else {
            // 第1个和第2个元素都不能超过INT上限
            for(int i = 1; i < size-1; i++) {
                if(stoll(S.substr(0, i)) > INT_MAX) {
                    break;
                }
                for(int j = i+1; j < size; j++) {
                    if(stoll(S.substr(i, j-i)) > INT_MAX) {
                        break;
                    }
                    ans = fibonacci(S, i, j);
                    if(ans.size() >= 3) {
                        return ans;
                    }
                }
            }
        }
        return {};
    }
};
// @lc code=end

