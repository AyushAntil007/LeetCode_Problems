class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low = 0, high = n - 1;
        int idx=-1;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        else if(nums[mid]<target){
            idx=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return idx+1;
    }
};