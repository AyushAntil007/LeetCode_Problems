class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mpp;

        int prefSum = 0;
        int cnt = 0;

        for(int i=0; i<n; i++) {

            prefSum += nums[i];

            if(prefSum== k) cnt++;

            int leftover = prefSum - k;

            if(!mpp.empty() && mpp.find(leftover) != mpp.end()) {

                cnt += mpp[leftover];
                
            }

            mpp[prefSum] ++;


        }

        return cnt;

          
        
    }
};