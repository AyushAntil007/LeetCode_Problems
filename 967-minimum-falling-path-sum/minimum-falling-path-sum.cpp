class Solution {
public:
int solve(int i,int j,vector<vector<int>>&matrix  ,vector<vector<int>>&dp){
    if(j<0||j>=matrix.size())return INT_MAX;
    if(i==0)return matrix[i][j];
    

    if(dp[i][j]!=-1)return dp[i][j];

    int ldiag=solve(i-1,j-1,matrix,dp);
    int up=solve(i-1,j,matrix,dp);
    int rdiag=solve(i-1,j+1,matrix,dp);

    return dp[i][j]=matrix[i][j]+ min(min(ldiag,rdiag),up);
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();


        //MEMOISATION...

        vector<vector<int>>dp(n,vector<int>(n,-1));
        // int ans=INT_MAX;
        // for(int c=0;c<n;c++){
        //     int mini=solve(n-1,c,matrix,dp);
        //     ans=min(mini,ans);
        // }
        // return ans;


        //TABULATION....

        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                
                int ldiag=(j-1<0)?INT_MAX : dp[i-1][j-1];

                int up=dp[i-1][j];

                int rdiag=(j+1>=n)?INT_MAX:dp[i-1][j+1];

                dp[i][j]=matrix[i][j]+min(min(ldiag,rdiag),up);


            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;

    }
};