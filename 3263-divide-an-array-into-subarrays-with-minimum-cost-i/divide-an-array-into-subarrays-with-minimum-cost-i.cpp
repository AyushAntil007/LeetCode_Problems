class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()<3)return 0;

        int minSum=nums[0];

        int mini=INT_MAX;
        int idx1=-1;


        for(int i=1; i<n; i++){
           if(nums[i]<mini){
            mini=nums[i];
            idx1=i;
           }
        }


        int secMini=INT_MAX;
        int idx2=-1;
        for(int i=1; i<n; i++){
            if(i!=idx1 && secMini>nums[i]){
                secMini=nums[i];
                idx2=i;
            }

        }

        return minSum+mini+secMini;
        
    }
};