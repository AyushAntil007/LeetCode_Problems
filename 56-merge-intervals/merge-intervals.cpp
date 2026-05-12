class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {

        int n = it.size();

        if(n== 1)return it;

        sort(it.begin(), it.end());

        int start = it[0][0];
        int end = it[0][1];

        vector<vector<int>>ans;

        for(int i=1; i<n; i++) {

            if(end < it[i][0]) {
                ans.push_back({start, end});
                start = it[i][0];
                end = it[i][1];
            }

            else {
                end = max(end, it[i][1]);
            }

        }

        ans.push_back({start,end});

        return ans;


        
    }
};