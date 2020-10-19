#include "leetcode-definition.h"

#include <vector>
#include <unordered_map>
using namespace std;

#define INPUT "1.txt"

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index; //数组值->下标
        for(int i = 0; i < nums.size(); i++) {
            index[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            if(index.find(left) != index.end() && index[left] != i) {
                return {i, index[left]};
            }
        }
        return {};
    }
};
// @lc code=end

