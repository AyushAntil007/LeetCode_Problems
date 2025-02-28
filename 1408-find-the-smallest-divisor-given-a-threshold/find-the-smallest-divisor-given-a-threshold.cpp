class Solution {
public:
bool possible(vector<int>&nums,int divisor,int threshold){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=ceil((double)nums[i]/divisor);   //use double to keep decimal values
    }
    return sum<=threshold;
}
int binarySearch(vector<int>&nums,int threshold,int low,int high){
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(nums,mid,threshold)){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=INT_MIN;

       for(int i=0;i<n;i++){
        // if(nums[i]<=mini)mini=nums[i];    // mini no need bcoz it will be "1"
        if(nums[i]>maxi)maxi=nums[i];
       }
        
        //brute force
    //    for(int i=1;i<=maxi;i++){
    //     if(possible(nums,i,threshold)){
    //         return i;
    //     }
    //    }
    //    return -1;

       //optimal sol

       return binarySearch(nums,threshold,1,maxi);
    }
};