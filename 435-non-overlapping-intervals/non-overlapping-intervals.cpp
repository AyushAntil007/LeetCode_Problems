class Solution {
public:
    bool static compare(vector<int> a, vector<int> b) { 
        return a[1] < b[1];
         }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(), v.end(), compare);

        int count = 0;
        int lastEndTime =
            v[0][1]; // last meet jo held hui thi uska end time pata hona chaiye

        for (int i = 1; i < n; i++) {
            if (v[i][0] < lastEndTime) {
                count++;  //count overlapping intervals
               
            }
            else {
             lastEndTime = v[i][1];  //update the lastEndTime if there is non overlap

            }
        }
        return count;
    
}
}
;