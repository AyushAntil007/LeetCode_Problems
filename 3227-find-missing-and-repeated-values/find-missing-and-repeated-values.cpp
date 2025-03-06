class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mpp;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mpp[grid[i][j]]++;
            }
        }
        int a,b;
        for(int i=1;i<=n*n;i++){
            if(mpp[i]>1)a=i;
            else if(mpp[i]==0)b=i;
        }
        return {a,b};
    }
};