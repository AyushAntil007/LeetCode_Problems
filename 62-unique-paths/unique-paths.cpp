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
        return solve(m-1,n-1, m,n,dp);
    }
};