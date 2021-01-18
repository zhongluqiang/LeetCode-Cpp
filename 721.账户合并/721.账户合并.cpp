#include "leetcode-definition.h"
#include <bits/stdc++.h>
using namespace std;
#define INPUT "721.txt"
/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class Solution {
    class DSU {
        private:
            vector<int> parent;
        public:
            DSU(int n) : parent(n) {
                for(int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }
            void merge(int x, int y) {
                parent[find(x)] = find(y);
            }
            int find(int x) {
                return x == parent[x] ? x : find(parent[x]);
            }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> email2idx; // 关键是对每个email地址进行编号，然后应用并查集把同一集合的归类到一起
        map<string, string> email2name;
        int count = 0;
        for(auto &account : accounts) {
            string &name = account[0];
            for(int i = 1, size = account.size(); i < size; i++) {
                string &email = account[i];
                if(!email2idx.count(email)) {
                    email2idx[email] = count++;
                    email2name[email] = name;
                }
            }
        }

        // 接下来合并邮箱集合
        DSU dsu(count);
        for(auto &account : accounts) {
            string &firstEmail = account[1];
            int firstIdx = email2idx[firstEmail];
            for(int i = 2, size = account.size(); i < size; i++) {
                string &nextEmail = account[i];
                int nextIdx = email2idx[nextEmail];
                dsu.merge(firstIdx, nextIdx);
            }
        }

        // 记录同一个集合下面有哪些邮箱
        map<int, vector<string>> index2emails;
        for(auto &p : email2idx) {
            string email = p.first;
            int index = p.second;
            index = dsu.find(index);
            index2emails[index].push_back(email);
        }

        // 提取同一个集合的所有邮箱及账号名
        vector<vector<string>> ans;
        for(auto &p : index2emails) {
            vector<string> &emails = p.second;
            sort(emails.begin(), emails.end());
            string name = email2name[emails[0]];
            vector<string> info;
            info.push_back(name);
            for(auto &email : emails) {
                info.push_back(email);
            }
            ans.push_back(info);
        }
        return ans;
    }
};
// @lc code=end

