class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int inc=0,dec=0;

        if(nums[0]>=nums[1])return false;

        int n=nums.size();
        int i=1;
        
            while(i<n && nums[i-1]<nums[i]){
                i++;
            }

            if(i==n)return false;

            while(i<n && nums[i-1]>nums[i]){
               i++;
            }

            if(i==n)return false;
           
           while(i<n && nums[i-1]<nums[i] )i++;

           return i==n;

       
        
       
        
    }
};