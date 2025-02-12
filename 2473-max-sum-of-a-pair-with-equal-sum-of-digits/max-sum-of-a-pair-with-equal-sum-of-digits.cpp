class Solution {
public:

    int countSum(int num){
        int sum=0;
        while(num){
             sum+=num%10;
             num=num/10;
        }
        return sum;
    }

  
    int maximumSum(vector<int>& nums) {

        int maxSum=INT_MIN;

        //tle....brute force

        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(countSum(nums[i])==countSum(nums[j])){
        //             maxSum=max(maxSum,nums[i]+nums[j]);
        //         }
        //     }
        // }

        // optimal...sort

        map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            int sum=countSum(nums[i]);
            if(mpp.find(sum)!=mpp.end()){
                maxSum=max(nums[i]+mpp[sum],maxSum);
                mpp[sum]=max(nums[i],mpp[sum]);
            }
            else{
                mpp[sum]=nums[i];
            }
            
        }
         
        
        
        
        if(maxSum!=INT_MIN){
            return maxSum;
        }
        return -1;
    }
};