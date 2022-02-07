#include "leetcode-definition.h"
/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

// @lc code=start
class Solution {
    struct Alpha {
        int num;
        int ch;
        // 默认排序按从大到小排序
        bool operator<(Alpha &r) {
            return num > r.num;
        }
    };

    /**
     * @brief 当前结尾字符为cur，当前数量按从大到小排序的字母为alphas
     * @note 只需要关注数量排名前二的字母
     * @return 返回当前可以生成的头两个或1个字符的字符串，比如"cc", "b"这样的
     *         如果没法生成字符串，则返回空字符串
     */
    string makeStr(vector<Alpha> &alphas, int &cur) {
        string ans;
        if(alphas[0].num <= 0) {
            return ans;
        }
        // 优先安排当前数量最多的字母，除非这个字母不能用
        if(cur != alphas[0].ch) {
            int count = min(alphas[0].num, 2);
            ans = string(count, alphas[0].ch);
            alphas[0].num -= count;
            cur = alphas[0].ch;
            return ans;
        }
        if(alphas[1].num <= 0) {
            return ans;
        }
        // 数量最多的字母不能用时，再安排数量第二多的字母
        // 在数量最多的字母没用完的情况下，数量第二多的字母只需要取1个即可
        // 这样可以优先让数量最多的字母用完
        ans = string(1, alphas[1].ch);
        alphas[1].num -= 1;
        cur = alphas[1].ch;
        return ans;
    }

public:
    string longestDiverseString(int a, int b, int c) {
        vector<Alpha> alphas{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        string ans;
        int cur = 0;

        while(1) {
            // 先排序剩余数组，按从大到小排序
            sort(alphas.begin(), alphas.end());
            string tmp = makeStr(alphas, cur);
            if(tmp.empty()) {
                break;
            }
            ans += tmp;
        }
        return ans;
    }
};
// @lc code=end

