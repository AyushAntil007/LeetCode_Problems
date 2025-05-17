class Solution {
public:
int countSum(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
    if(idx==0){
       if(target==0&& nums[0]==0)return 2;
       if(target==0||nums[0]==target)return 1;
        return 0;
    } 
        if(dp[idx][target]!=-1)return dp[idx][target];
        
        int not_take=countSum(idx-1,target,nums,dp);
        int take=0;
        if(nums[idx]<=target){
           take=countSum(idx-1,target-nums[idx],nums,dp);
        }
        
        return take+not_take;
    
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int tsum=0;
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }

        if(tsum<(target))return 0;     //take absolute target
        if((tsum-target)%2!=0)return 0;

        int s1=(tsum-target)/2;   //new target....minimum

       
    
       //memoisation....
       //   vector<vector<int>>dp(n,vector<int>(s1+1,-1));

       // return countSum(n-1,s1,nums,dp);


       //tabulation......

        vector<vector<int>>dp(n,vector<int>(s1+1,0));  //declare by 0 noy by -1
        // Base cases
        if (nums[0] == 0) dp[0][0] = 2;  // pick or not pick
        else dp[0][0] = 1;              // only one way: not pick

        if (nums[0] != 0 && nums[0] <= s1)
            dp[0][nums[0]] = 1;

       for(int i=1;i<n;i++){
        for(int j=0;j<s1+1;j++){
            int not_take=dp[i-1][j];
            int take=0;
            if(nums[i]<=j){
                take=dp[i-1][j-nums[i]];
            }
            dp[i][j]=not_take+take;
        }
       }
       return dp[n-1][s1];
    }
};