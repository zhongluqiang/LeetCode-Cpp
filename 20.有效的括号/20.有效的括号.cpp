#include "leetcode-definition.h"
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;
#define INPUT "20.txt"
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> quotes;
        map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};

        for(auto ch : s) {
            switch (ch)
            {
                case '(': 
                case '{': 
                case '[': 
                    quotes.push(ch);
                        break;
                case ')':
                case '}':
                case ']':
                    if(quotes.empty() || quotes.top() != pairs[ch]) {
                        return false;
                    } else {
                        quotes.pop();
                    }
                    break;
                default:
                    break;
            }
        }

        if(quotes.empty()) {
            return true;
        } else {
            return false;
        }
    } // end isValid
};
// @lc code=end

