class Solution {
public:

    int solve(int r, int c, int m, int n, vector<vector<int>>&dp){
        if(r==0&& c==0)return 1;

        if(r<0||r>=m||c<0||c>=n)return 0;

        if(dp[r][c]!=-1)return dp[r][c];

        int up=solve(r-1,c,m,n,dp);
        int left=solve(r,c-1,m,n,dp);

        return dp[r][c]=left+up;
    }
    int uniquePaths(int m, int n) {

        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //return solve(m-1,n-1, m,n,dp);

        dp[0][0]=1;

        

        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                 if (i == 0 && j == 0) continue; // already set

                int left=0,up=0;
                if(j>0){
                    left=dp[i][j-1];
                }
                if(i>0){
                    up=dp[i-1][j];
                }

                dp[i][j]=left+up;
               
            }
        }

        return dp[m-1][n-1];
    }
};