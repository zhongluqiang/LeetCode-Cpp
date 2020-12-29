#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
# if 0
class Solution {
public:
    // 一轮二分查找找出与target相等的位置，再从这个位置扩展结果，target与nums内的全部元素都相同时会退化成O(n)
    vector<int> searchRange(vector<int>& nums, int target) {
        const int size = nums.size();
        if(size == 0) { return {-1, -1}; }

        int mid, low = 0, high = size-1;
        while(low <= high) {
            mid = low + (high-low) / 2;
            if(nums[mid] == target) {
                break;
            } else if(nums[mid] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        if(low > high) {
            return {-1, -1};
        }
        int a = mid, b = mid;
        while(a >= 0 && nums[a] == target) { a--; }
        a++;
        while(b <= size-1 && nums[b] == target) { b++; }
        b--;
        return {a, b};
        
    }
};
#else 
class Solution {
public:
    // 两轮二分查找，第一轮找出左侧边界，第二轮找出右侧边界，即便最差情况下也可以保证O(n)复杂度
    vector<int> searchRange(vector<int>& nums, int target) {
        const int size = nums.size();
        if(size <= 0) { return {-1, -1}; }

        vector<int> ans(2, -1);
        int mid, low = 0, high = size-1;
        // 这一轮找左边界
        while(low < high) {
            mid = low + (high-low) / 2;
            if(nums[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if(nums[low] != target) { return ans; }
        ans[0] = low;

        // 这一轮找右边界
        high = size;
        while(low < high) {
            mid = low + (high-low) / 2;
            if(nums[mid] <= target) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        ans[1] = low-1;
        return ans;
    }
};
#endif
// @lc code=end

