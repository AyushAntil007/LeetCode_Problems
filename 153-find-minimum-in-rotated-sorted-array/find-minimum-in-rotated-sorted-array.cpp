class Solution {
public:
    int binarySearch(vector<int>&nums,int left,int right){
        while(left<right){
            int mid=(left+right)/2;
            
            // If mid element is greater than rightmost, the min is in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Otherwise, min is in the left half (including mid)
            else {
                right = mid;
            }
        }
        
        return nums[left];  // left points to the smallest element
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        
       return binarySearch(nums,0,n-1);
        
    }
};