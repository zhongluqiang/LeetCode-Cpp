#include "leetcode-definition.h"
#include <map>
using namespace std;
#define INPUT "202.txt"
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    // 计算n每个位置的数的平方和
    static int sum_square(int n) {
        int sum = 0;
        while(n > 0) {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        map<int, bool> found;

        int sum = 0;
        while(1) {
            sum = sum_square(n);
            if(sum == 1) {
                return true;
            }
            if(found.find(sum) != found.end()) {
                return false;
            }
            found[sum] = true;
            n = sum;
        }
    }
};
// @lc code=end

