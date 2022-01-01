/*
 * @lc app=leetcode.cn id=2022 lang=cpp
 *
 * [2022] 将一维数组转变成二维数组
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;

        if(m*n != original.size()) {
            return ans;
        }

        for(int row = 0; row < m; row++) {
            vector<int> tmp;
            for(int col = 0; col < n; col++) {
                tmp.push_back(original[row*n + col]);
            }

            ans.push_back(tmp);
        }

        return ans;
    }
};
// @lc code=end

