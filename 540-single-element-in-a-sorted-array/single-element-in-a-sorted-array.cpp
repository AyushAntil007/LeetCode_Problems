class Solution {
public:
int binarySearch(vector<int>&nums,int left,int right){
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])return nums[mid];

            if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            if (nums[mid] ==nums[mid-1]) {
                if(mid%2==0){
                   right=mid-1;
                }
                else{
                   left=mid+1;
                }
            }
           
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)return nums[0];
         if (nums[0] != nums[1]) return nums[0];
         if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        return binarySearch(nums,0,n-1);
    }
};