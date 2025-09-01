class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& pack) {
        
        intervals.push_back(pack);
        int n=intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;

        int start=intervals[0][0];
        int end=intervals[0][1];


        for(int i=1; i<n; i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);

            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }

        ans.push_back({start,end});

        return ans;
    }
};