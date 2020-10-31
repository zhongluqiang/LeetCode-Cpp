#include <vector>
#include <climits>
using namespace std;

/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    // sum[i]表示区间[0~i]的和, sum[i,j] = sum[j] - sum[i-1]
    vector<int> sum;
    vector<int> _nums;
public:
    NumArray(vector<int>& nums) {
        const int n = nums.size();
        sum = vector<int>(n, INT_MIN);
        _nums = nums;
        if(n > 0) { // 预防输入数组为空
            sum[0] = nums[0];  
        }
    }
    
    int sumRange(int i, int j) {
        if(sum[j] == INT_MIN) {
            for(int ii = 1; ii <= j; ii++) {
                if(sum[ii] != INT_MIN) {
                    continue;
                } else {
                    sum[ii] = _nums[ii] + sum[ii-1];
                }
            }
        }
        if(i == 0){
            return sum[j];
        } else {
            return sum[j] - sum[i-1];
        }
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

