class Solution {
public:
int solve(int idx,int pidx,vector<int>&nums,vector<vector<int>>&dp){
    if(idx==nums.size())return 0;
    if(dp[idx][pidx+1]!=-1)return dp[idx][pidx+1];

    int not_take=0+solve(idx+1,pidx,nums,dp);
    int take=0;
    if(pidx==-1||nums[idx]>nums[pidx]){
        take=1+solve(idx+1,idx,nums,dp);
    }
    return dp[idx][pidx+1]=max(take,not_take);
    
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        //memeoisation
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(0,-1,nums,dp);

        //tabulation
       vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // dp[idx][prev+1]

        for (int idx = n-1; idx >= 0; idx--) {
            for (int prev = idx-1; prev >= -1; prev--) {
                int notTake = dp[idx+1][prev+1];
                int take = 0;
                if (prev == -1 || nums[idx] > nums[prev]) {
                    take = 1 + dp[idx+1][idx+1];
                }
                dp[idx][prev+1] = max(take, notTake);
            }
        }

        return dp[0][0];
        
    }
};