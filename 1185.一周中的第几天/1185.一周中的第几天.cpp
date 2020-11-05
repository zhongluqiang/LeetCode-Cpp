#include "leetcode-definition.h"
#include <string>
using namespace std;
#define INPUT "1185.txt"
/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
class Solution {
public:
    // 闰年判断条件：能被4整除但不能被100整除，或者能被400整除
    bool isLeapYear(int year) {
        if(year%4 == 0 && year%100 != 0 || year%400 == 0) {
            return true;
        } else {
            return false;
        }
    }

    string dayOfTheWeek(int day, int month, int year) {
        const int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        const string weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        int days = 0;
        for(int i = 1971; i < year; i++) {
            if(isLeapYear(i)) {
                days += 366;
            } else {
                days += 365;
            }
        }
        for(int i = 1; i < month; i++) {
            days += daysOfMonth[i];
        }
        if(isLeapYear(year) && month > 2) {
            days++;
        }
        days += (day-1);

        return weekday[(days+5)%7];
    }
};
// @lc code=end

