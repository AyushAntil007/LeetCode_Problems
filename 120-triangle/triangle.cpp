class Solution {
public:

//MEMOISATION....

int solve(int r,int c,int m,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    if(r==m-1)return triangle[r][c];

    if(r>=m||c>=triangle[r].size())return INT_MAX;

    if(dp[r][c]!=-1)return dp[r][c];

    int pick=triangle[r][c]+solve(r+1,c,m,triangle,dp);
    int n_pick=triangle[r][c]+solve(r+1,c+1,m,triangle,dp);

    return dp[r][c]=min(pick,n_pick);
}

//RECURSION......

// int solve(int r,int c,int m,vector<vector<int>>&triangle){
//     if(r==m-1)return triangle[r][c];

//     if(r>=m||c>=triangle[r].size())return INT_MAX;

//     int pick=triangle[r][c]+solve(r+1,c,m,triangle);
//     int n_pick=triangle[r][c]+solve(r+1,c+1,m,triangle);

//     return min(pick,n_pick);
// }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();

        //int mini=solve(0,0,m,triangle);
        vector<vector<int>>dp(m,vector<int>(m,-1));
        int mini=solve(0,0,m,triangle,dp);
        return mini;
        
    }
};