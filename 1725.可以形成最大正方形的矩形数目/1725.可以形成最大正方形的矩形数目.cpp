class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        int count = 0;
        int l, w, k;
        for(auto &rec : rectangles) {
            l = rec[0];
            w = rec[1];
            k = min(l, w);
            if(k > maxLen) {
                count = 1;
                maxLen = k;
            } else if(k == maxLen) {
                count++;
            } else {
                // continue;
            }
        }
        return count;
    }
};