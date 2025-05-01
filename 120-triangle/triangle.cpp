class Solution {
public:

//MEMOISATION....

int solve(int r,int c,int m,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    if(r==m-1)return triangle[r][c];

    if(r>=m||c>=triangle[r].size())return INT_MAX;

    if(dp[r][c]!=-1)return dp[r][c];

    int down=triangle[r][c]+solve(r+1,c,m,triangle,dp);
    int diag=triangle[r][c]+solve(r+1,c+1,m,triangle,dp);

    return dp[r][c]=min(down,diag);
}

//RECURSION......

// int solve(int r,int c,int m,vector<vector<int>>&triangle){
//     if(r==m-1)return triangle[r][c];

//     if(r>=m||c>=triangle[r].size())return INT_MAX;

//     int down=triangle[r][c]+solve(r+1,c,m,triangle);
//     int diag=triangle[r][c]+solve(r+1,c+1,m,triangle);

//     return min(down,diag);
// }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();

        //int mini=solve(0,0,m,triangle);
        vector<vector<int>>dp(m,vector<int>(m,-1));
        //int mini=solve(0,0,m,triangle,dp);


        //TABULATION....

        for(int c=0;c<m;c++){
            dp[m-1][c]=triangle[m-1][c];
        }

        for(int i=m-2;i>=0;i--){    //start from last second row
            for(int j=i;j>=0;j--){
                
                int down=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];

                dp[i][j]=min(down,diag);

            }
        }
        return dp[0][0];   // result stored
           

       // return mini;
        
    }
};