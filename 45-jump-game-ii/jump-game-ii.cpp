class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if(n<=1)return 0;

       
        int maxIdx=0;
        int curEnd =0;
        int jump=0;

        for(int i=0; i<n; i++) {
            maxIdx = max(maxIdx, i+nums[i]);
            if(i== curEnd) {
                jump++;
                curEnd=maxIdx;

            }

            if(curEnd>=n-1)  return jump;

            
        }
        return 0;
        
    }
};