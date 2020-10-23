#include "leetcode-definition.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define INPUT "959.txt"
/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */

// @lc code=start
class Solution {
    // 并查集数组结构
    class DSU {
    private:
        vector<int> parent_; // 存储每个结点的根结点，一个根结点表示一个集合
    public:
        DSU(int n) : parent_(n) {
            for(int i = 0; i < n; i++) {
                parent_[i] = i; // 初始时将每个结点看一个独立的集合，也就是根是其自身
            }
        }
        //查找结点x的根结点，如果x本身是根结点，那么parent_[x] == x 并且 find(x) == x
        int find(int x) {
            if(parent_[x] != x) {
                parent_[x] = find(parent_[x]);
            }
            return parent_[x];
        }
        //合并两个结点
        void merge(int x, int y) {
            //将x的根结点设置成y的根结点
            parent_[find(x)] = find(y); 
        }
    };
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(4*n*n);
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                // 每个格子分成四个部分，第一个部分的起始下标
                int index = 4 * (r * n + c);
                // 合并一个格子内的四个部分
                switch (grid[r][c]) {
                    case '/':
                        dsu.merge(index + 0, index + 3);
                        dsu.merge(index + 1, index + 2);
                        break;
                    case '\\':
                        dsu.merge(index + 0, index + 1);
                        dsu.merge(index + 2, index + 3);
                        break;
                    case ' ':
                        dsu.merge(index + 0, index + 1);
                        dsu.merge(index + 1, index + 2);
                        dsu.merge(index + 2, index + 3);
                        break;
                    default:
                        break;
                }
                //与下面和右边的格子进行合并
                if(r + 1 < n) {
                    dsu.merge(index + 2, index + 4 * n + 0);
                }
                if(c + 1 < n) {
                    dsu.merge(index + 1, index + 4 + 3);
                }
            }
        }
        int ans = 0;
        // 查找并查集中的所有的根结点，判断条件是dsu.find(x) == x
        for(int i = 0; i < 4*n*n; i++) {
            if(dsu.find(i) == i) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

