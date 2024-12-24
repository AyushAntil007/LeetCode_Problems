class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        // brute force
        // int maxi = INT_MIN;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         int sum = 0;
        //         // add all the elements of subarray:
        //         for (int k = i; k <= j; k++) {
        //             sum += arr[k];
        //         }
        //         maxi = max(maxi, sum);
        //     }
        // }
        // return maxi;

        // better solution

        // maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=arr[j];
        //         maxi=max(maxi,sum);
        //     }
        // }
        // return maxi;

        // optimal solution

        //..........Kadanes Algorithm..........

         int current_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < n; i++) {
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};