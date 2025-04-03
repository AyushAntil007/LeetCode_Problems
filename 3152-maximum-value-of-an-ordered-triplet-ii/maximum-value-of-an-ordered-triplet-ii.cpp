
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxElt=0, maxTriplet=0,maxDiff=0;

        for(int i=0;i<n;i++){
            maxTriplet=max(maxTriplet,maxDiff*nums[i]);
            maxDiff=max(maxDiff,maxElt-nums[i]);
            maxElt=max(maxElt,(long long)nums[i]);

        }
        return maxTriplet;
        
    }
};