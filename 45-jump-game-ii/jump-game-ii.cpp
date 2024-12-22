class Solution {
public:
    // brute force

    //  int solve(int idx,int jump,vector<int>&nums,int n){
    //      if(idx>=n-1)return jump;
    //      int mini=INT_MAX;
    //      for(int i=1;i<=nums[idx];i++){
    //          mini=min(mini,solve(idx+i,jump+1,nums,n));
    //      }
    //      return mini;
    //  }
    //      int jump(vector<int>& nums) {
    //           int n = nums.size();
    //         int idx=0;
    //         int jump=0;
    //         return solve(idx,jump,nums,n);

    //     }

    // dp

    // int solve(int idx, int jump, vector<int>& nums, int n,
    //           vector<vector<int>>& dp) {

    //     if (idx >= n - 1)
    //         return jump;

    //      if (dp[idx][jump] != -1)
    //         return dp[idx][jump];

    //     int mini = INT_MAX;
    //     for (int i = 1; i <= nums[idx]; i++) {
    //         mini = min(mini, solve(idx + i, jump + 1, nums, n, dp));
    //     }
    //     return dp[idx][jump] = mini;
    // }
    int jump(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int jump = 0;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(idx, jump, nums, n, dp);

        // optimsal approach

        int l = 0, r = 0;
        while (r < n - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(i + nums[i], farthest); //is range se max reachable index nikal rahe hai
            }
            l = r + 1;     // l will update before r
            r = farthest;  // r represents max index

            jump++;
        }
        return jump;
    }
};