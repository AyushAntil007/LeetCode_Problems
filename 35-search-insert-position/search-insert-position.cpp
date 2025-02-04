class Solution {
public:

int bSearch(vector<int>&nums,int low,int high,int target){
        int idx=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)return mid;
            else if(target>nums[mid]){
                low=mid+1;
                idx=mid+1;
            }
            
            else{
                high=mid-1;
                idx=mid;   // mid ayega
            }
        }

        if(idx==-1)return 0;  // check for boundaries 
        return idx;
        
    }
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        return bSearch(nums,0,n-1,target);
    }
};