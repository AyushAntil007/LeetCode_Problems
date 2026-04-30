class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        if(n==0)return -1;

        int curSum =0;
        int totalSum =nums[0];

        for(int i=0; i<nums.size(); i++){
            curSum =curSum+nums[i];

            if(nums[i] > curSum) curSum = nums[i];

            totalSum = max(curSum, totalSum);
        }

        return totalSum;


    }
};