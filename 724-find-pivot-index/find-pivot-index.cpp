class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int idx =-1;

        int rSum=0;
        int lSum=0;

        int n= nums.size();

        vector<int>left(n);
        vector<int>right(n);

        for(int i=0; i<n; i++) {
            left[i]=lSum;
            lSum += nums[i];

            right[n-1-i] = rSum;
            rSum += nums[n-1 - i];
        }

        for(int i=0; i<n ; i++) {
            if(left[i] == right[i]) {
                idx=i;
                break;
            }

        }
        return idx;
        
    }
};