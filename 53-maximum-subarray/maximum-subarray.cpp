class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int cur=0;
        int maxi=INT_MIN;

        for(int i=0; i<nums.size(); i++){
            cur=max(cur+nums[i], nums[i]);
            maxi=max(cur , maxi);
        }
        return maxi;
        
    }
};