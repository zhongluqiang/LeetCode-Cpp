#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
using namespace std;

#define INPUT "15.txt"
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) { return result; }

        sort(nums.begin(), nums.end());

        auto it = nums.begin();
        while(it != nums.end() - 2) {
            int now = *it;
            auto leftpos = it + 1;
            auto rightpos = nums.end() - 1;

            while(leftpos < rightpos) {
                int leftvalue = *leftpos;
                int rightvalue = *rightpos;
                int sum = leftvalue + rightvalue + now;
                if(sum == 0) {
                    result.push_back(vector<int>{now, leftvalue, rightvalue});
                    //leftpos和rightpos分别指向下一个不同的值，避免结果重复
                    do {
                        leftpos++;
                    } while(*leftpos == leftvalue && leftpos < rightpos);
                    do {
                        rightpos--;
                    } while(*rightpos == rightvalue && rightpos > leftpos);
                } else if(sum > 0) {
                    rightpos--;
                } else {
                    leftpos++;
                }
            }
            
            // it指向下一个与当前值不同的位置
            do {
                it++;
            }while(*it == now && it !=nums.end() - 2);
        }

        return result;
    }
};
// @lc code=end

