class Solution {
public:
    int binarySearch(vector<int>&nums,int left,int right){
        int mini=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            
            // whole, arrray is sorted
             if(nums[left]<=nums[right]){
                mini=min(mini,nums[left]);
                break;
            }
            // if left is sorted
            if (nums[mid]>=nums[left]) {
                mini=min(mini,nums[left]);
                left=mid+1;
            }
            // Otherwise, min is in the left half (including mid)
            else {
                mini=min(mini,nums[mid]);
                right=mid-1;
            }
        }
        
        return mini;  // left points to the smallest element
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        
       return binarySearch(nums,0,n-1);
        
    }
};