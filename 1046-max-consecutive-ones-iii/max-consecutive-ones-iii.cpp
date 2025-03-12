class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        int maxCount=0;
        int count0=0;
        // vector<int>idx;

        int l=0,r=0;
        while(r<n){
            if(nums[r]==0){
                count0++;
                //idx.push_back(r);
            }
            if(count0>k){
                // count0--;
                // l=idx[0]+1;
                // idx.erase(idx.begin());

                if(nums[l]==0)count0--;
                l++;
            }
            if(count0<=k){
                maxCount=max(maxCount,r-l+1);
            }
            r++; 
             
        }

        return maxCount;
    }
};