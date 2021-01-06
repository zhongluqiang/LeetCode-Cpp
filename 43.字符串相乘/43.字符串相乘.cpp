#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "43.txt"
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#if 0
class Solution {
    string add(string num1, string num2) {
        string ans;
        int sum = 0, carry = 0;
        while(num1.size() > 0 && num2.size() > 0) {
            sum = num1.back() - '0' + num2.back() - '0' + carry;
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.insert(ans.begin(), sum+'0');
            num1.pop_back();
            num2.pop_back();
        }
        while(num1.size() > 0) {
            sum = num1.back() - '0' + carry;
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.insert(ans.begin(), sum+'0');
            num1.pop_back();
        }
        while(num2.size() > 0) {
            sum = num2.back() - '0' + carry;
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.insert(ans.begin(), sum+'0');
            num2.pop_back();
        }
        if(carry > 0) {
            ans.insert(ans.begin(), '1');
        }
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") { return "0"; }
        if(num1.size() < num2.size()) {
            swap(num1, num2); // 保证num2是长度较短的数
        }
        
        string ans;
        string tmp;
        string weight;
        while(num2.size() > 0) {
            tmp.clear();
            int x = num2.back() - '0'; num2.pop_back(); // 取最后一位数
            if(x != 0) {
                for(int i = 0; i < x; i++) {
                    tmp = add(tmp, num1);
                }
                tmp += weight;
            }
            ans = add(ans, tmp);
            weight += "0";
        }
        return ans;
    }
};
#else 
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") { return "0"; }

        const int n1 = num1.size();
        const int n2 = num2.size();
        vector<int> index(n1+n2); // n1长度的数和n2长度的数相乘，结果不会超过n1+n2位

        // num1[i]与num2[j]相乘的结果存放在index[i+j+1]中
        for(int i = n1-1; i >= 0; i--) {
            for(int j = n2-1; j >= 0; j--) {
                index[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        // 处理index中的进位
        int carry = 0;
        for(int i = index.size()-1; i >= 0; i--) {
            index[i] += carry;
            carry = index[i] / 10;
            index[i] %= 10;
        }
        // 结果第1位为零时跳过
        string ans;
        int pos = 0;
        if(index[pos] == 0) { pos++; }
        while(pos < index.size()) {
            ans.push_back(index[pos]+'0'); 
            pos++; 
        }
        return ans;
    }
};
#endif
// @lc code=end

