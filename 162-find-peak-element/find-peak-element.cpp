class Solution {
public:
int binarySearch(vector<int>&nums,int left,int right){
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>=nums[mid-1]&&nums[mid]>=nums[mid+1])return mid;

            if(nums[mid]<nums[mid+1]){
                left=mid+1;
            }
            else if (nums[mid] <nums[mid-1]) {
                right=mid;
            }
           
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        return binarySearch(nums,0,n-1);
    }
};