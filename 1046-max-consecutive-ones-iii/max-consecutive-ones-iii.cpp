class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int len=INT_MIN;

        // brute force


        // for(int i=0;i<n;i++){
        //     int cnt1=0;
        //     int cnt0=0;

        //     for(int j =i; j<n ;j++){

        //         if(nums[j]==1)cnt1++;
        //         else{
        //             if(cnt0==k){
        //                 break;
        //             }
        //             cnt1++;
        //             cnt0++;

                    
        //         }
        //     }
        //     len=max(len,cnt1);
        // }



        // 2 pointers


        int left=0,right=0;
        int cnt0=0;

        while(right<n){
            if(nums[right]==1)right++;
            else{
                if(cnt0==k){
                    if(nums[left]==0)cnt0--;
                    left++;
                    
                }
                else{
                    cnt0++;
                     right++;
                }
               
               
            }
            len=max(len,right-left);
        }

        return len;
    }
};