class Solution {
public:
    int bSearchPos(vector<int>& nums, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= 0) {
                left = mid + 1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
    int bSearchNeg(vector<int>& nums, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= 0) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int pos = bSearchPos(nums, 0, n - 1);
        int neg = bSearchNeg(nums, 0, n - 1);

        int totalPos = n - pos-1;
        int totalNeg = neg ;

        return max(totalPos, totalNeg);
    }
};