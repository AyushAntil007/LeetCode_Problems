class Solution {
public:

int solve(int r, int c, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
    if(r<0 || c<0)return INT_MAX;

    if(r==0 && c==0)return grid[0][0];

    if(dp[r][c]!=-1)return dp[r][c];

    long long left=solve(r,c-1,m,n,grid,dp);
    long long up =solve(r-1,c,m,n, grid,dp);

    return  dp[r][c]=grid[r][c]+min(left,up);
}
    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<long long>>dp(m,vector<long long>(n,INT_MAX));

      //  return solve(m-1,n-1,m,n,grid,dp);

      for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            if(i==0&& j==0){
                dp[0][0]=grid[i][j];
                continue;
                }
            
            long long left=INT_MAX, up=INT_MAX;
            if(j>=1)left=dp[i][j-1];
               
           
            if(i>=1) up=dp[i-1][j];
            

            dp[i][j]=grid[i][j]+min(left,up);
        }
      }
        return dp[m-1][n-1];
    }
};