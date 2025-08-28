class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      //  int len=0;
        int n=nums.size();

        // for(int i=0; i<n; i++){
        //     int cnt0=0;
        //     for(int j=i; j<n; j++){
        //         if(nums[j]==0)cnt0++;
               
        //         if(cnt0>k){
        //             break;
        //         }
        //          len=max(len,j-i+1);

        //     }
        // }
        // return len;


        int left=0,right=0;
       vector<int>vec(2,0);
        int len=INT_MIN;

        while(right<nums.size()){
          vec[nums[right]]++;
            while(vec[0]>k){
                vec[nums[left]]--;
                left++;
            }
            len=max(right-left+1, len);
            right++;

        }

        return len;
    }
};