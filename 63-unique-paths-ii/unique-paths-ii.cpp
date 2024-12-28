class Solution {
public:
 // Memoization
    int memo(int m, int n, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid) {
        if(m>=0&&n>=0&&obstacleGrid[m][n]==1)return 0;  //obstacle

        if (m == 0 && n == 0) { // base case
            return 1;
        }
        if (m < 0 || n < 0) { // exceeds row or col
            return 0;
        }
        if (dp[m][n] != -1)
            return dp[m][n];
       int left = memo(m, n - 1,dp,obstacleGrid);
        int up = memo(m - 1, n,dp,obstacleGrid);
        return dp[m][n] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memo(m-1,n-1,dp,obstacleGrid);
    }
};