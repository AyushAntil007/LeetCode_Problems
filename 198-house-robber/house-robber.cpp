class Solution {
public:

int solve(int idx, vector<int>&nums,vector<int>&dp){
    if(idx==0)return nums[idx];

    if(dp[idx]!=-1)return dp[idx];

    int pick=nums[idx];  //importsnt
    if(idx>1){
        pick=nums[idx]+solve(idx-2,nums,dp);
    }
    int n_pick=solve(idx-1,nums,dp);


    return dp[idx]=max(pick,n_pick);
}
    int rob(vector<int>& nums) {

        int n=nums.size();

        vector<int>dp(n+1,-1);

        int ans=solve(n-1,nums,dp);
        return ans;
        
    }
};