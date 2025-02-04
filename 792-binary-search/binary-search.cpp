class Solution {
public:
    int bSearch(vector<int>&nums,int low,int high,int target){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)return mid;
            else if(target>nums[mid])low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int index=bSearch(nums,0,n-1,target);
        return index;
    }
};