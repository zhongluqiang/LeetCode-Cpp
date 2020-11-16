#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 边界条件
        if(denominator == 0) return "";
        if(numerator == 0) return "0";

        string result;
        // 转化为long long防止溢出
        long long num = static_cast<long long>(numerator);
        long long denom = static_cast<long long>(denominator);

        // 处理正负号，一正一负返回负
        if((num>0)^(denom>0)) result.push_back('-');

        // 分子分母转化成正数
        num = llabs(num);
        denom = llabs(denom);

        // 处理整数部分
        result.append(to_string(num/denom));

        // 处理小数部分
        num %= denom;
        if(num == 0) {
            return result;
        }
        result.push_back('.');
        int index = result.size() - 1; // index暂存每个商出现的位置，用于在循环时插入括号
        unordered_map<int, int> record; // record用于记录每次出现的余数以及出现的位置
        while(num && record.count(num) == 0) {
            record[num] = ++index;
            num *= 10;
            result += to_string(num/denom);
            num %= denom;
        }
        // 处理循环
        if(record.count(num) == 1) {
            result.insert(record[num], "(");
            result.push_back(')');
        }
        return result;
    }
};
// @lc code=end

