#include "leetcode-definition.h"
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define INPUT "1547.txt"
/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 *
 * [1547] 切棍子的最小成本
 */

// @lc code=start
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        const int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        // cuts[0]表示起点0，cuts[m+1]表示终点n，cuts[i]表示第i个切割点的位置，
        // 例如cuts[1]是第1个切割点，cuts[m]是最后一个切割点

        // f[i][j]表示以第i-1个切割点为左端点，第j+1个切割点为右端点的木棍全部切割之后的最小成本
        // 最终结果存储在f[1][m]中，也就是起点cuts[0]到终点cuts[m+1]的最小成本
        // f[i][j]中有j-i+1个切割点，分别是cuts[i],...,cuts[j]，这些切割点可以将区间切割成j-i+2段
        // 计算f[i][j]，可以枚举第1刀的位置。切割1刀之后，当前区间分成左右两个区间，这两个区间是
        // 规模较小的子问题，可以用同样的方法来求解。枚举完第1刀的位置后，以成本最小的位置作为最优秀解
        // 状态转移方程如下：
        // f[i][j] = (cuts[j+1] - cuts[i-1]) + min{f[i][k-1] + f[k+1][j]} | k>=i && k <= j
        // 状态转移的边界条件为：f[i][j] = 0，其中 i>j，表示没有可以切割的位置。
        vector<vector<int>> f(m+2, vector<int>(m+2));

        for(int i = m; i >= 1; i--) {
            for(int j = i; j <= m; j++) {
                f[i][j] = (i == j ? 0 : INT_MAX);
                for(int k = i; k <= j; k++) {
                    f[i][j] = min(f[i][j], f[i][k-1] + f[k+1][j]);
                }
                f[i][j] += cuts[j+1] - cuts[i-1];
            }
        }
        return f[1][m];
    }
};
// @lc code=end

