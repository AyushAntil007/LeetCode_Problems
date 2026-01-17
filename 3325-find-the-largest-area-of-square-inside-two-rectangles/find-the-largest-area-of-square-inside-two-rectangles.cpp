
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        
         int n = bl.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int left   = max(bl[i][0], bl[j][0]);
                int right  = min(tr[i][0], tr[j][0]);
                int bottom = max(bl[i][1], bl[j][1]);
                int top    = min(tr[i][1], tr[j][1]);

                if (right > left && top > bottom) {
                    long long side = min(right - left, top - bottom);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};