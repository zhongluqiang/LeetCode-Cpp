#include "leetcode-definition.h"
#define INPUT "969.txt"
/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        vector<int> index(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            index[arr[i]] = i;
        }

        vector<int> ans;
        
        for(int i = arr.size() - 1; i >= 1; i--) {
            int k = index[i]; // 找4的位置，3的位置，2的位置，1的位置
            ans.push_back(k);
            reverse(arr.begin() + 1, arr.begin() + k + 1);
            ans.push_back(i);
            reverse(arr.begin() + 1, arr.begin() + i + 1);
            for(int j = 1; j <= i; j++) {
                index[arr[j]] = j;
            }
        }
        return ans;
    }
};
// @lc code=end

