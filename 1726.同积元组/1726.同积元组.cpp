class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> index; // 乘积 -> 组合数
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i+1; j < nums.size(); j++) {
                index[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for(auto &[x, y] : index) {
            ans += (y-1)*y/2; // 从所有组合中选两个出来
        }
        return ans*8; // 每个组合可能生成8个不同排列的结果
    }
};