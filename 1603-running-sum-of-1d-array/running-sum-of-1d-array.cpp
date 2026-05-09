class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        long long prefSum =0;

        int n= nums.size();

        vector<int>  runSum(n);

        for(int i=0; i<n; i++) {
            prefSum += nums[i];
            runSum[i] = prefSum;
        }
        return runSum;
    }
};