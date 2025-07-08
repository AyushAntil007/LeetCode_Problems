class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        int curMax=0;
        int  tMax=nums[0];

        for(int i=0;i<n;i++){
            curMax=max(nums[i],curMax+nums[i]);
            tMax=max(tMax,curMax);
        }
        return tMax;

    }
};