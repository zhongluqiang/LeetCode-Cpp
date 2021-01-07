#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g; // g[A][B] = k -> A/B = k
        for(int i = 0; i < equations.size(); i++) {
            const string &A = equations[i][0];
            const string &B = equations[i][1];
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k; 
        }

        vector<double> ans;
        for(const auto &pair : queries) {
            const string &X = pair[0];
            const string &Y = pair[1];
            if(!g.count(X) || !g.count(Y)) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            ans.push_back(divide(X, Y, g, visited));
        }
        return ans;
    }

private:
    double divide(const string &A, const string &B, unordered_map<string, unordered_map<string, double>> &g, unordered_set<string> &visited) {
        if(A == B) {
            return 1.0;
        }
        visited.insert(A);
        for(const auto &pair : g[A]) {
            const string &C = pair.first;
            if(visited.count(C)) continue;
            double d = divide(C, B, g, visited);
            if(d > 0) {
                return d*g[A][C];
            }
        }
        return -1.0;
    }
};
// @lc code=end

