class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxStep=0;

        int n = nums.size();

        for(int i=0; i<n; i++){

            if(nums[i]==0 && maxStep == i && n>1)return false;

            maxStep = max( maxStep, i+nums[i]);

            if( maxStep>= n-1)return true;
        }

        return false;
        
    }
};