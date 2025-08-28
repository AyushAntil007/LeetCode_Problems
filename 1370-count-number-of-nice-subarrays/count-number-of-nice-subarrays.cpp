class Solution {
public:
int solve(vector<int>&nums,int k){
    int right=0,left=0;
        int odd=0;
        int n=nums.size();
        int cnt=0;

        while(right<n){
            if(nums[right]%2!=0)odd++;

            while(odd>k){
                if(nums[left]%2!=0)odd--;
                left++;
            }

            if(odd<=k)cnt+=right-left+1;
            right++;

        }
        return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0;

        int n=nums.size();

        // for(int i=0; i<n; i++){
        //     int odd=0;
        //     for(int j=i; j<n; j++){

        //         if(nums[j]%2!=0)odd++;

        //         if(odd==k){
        //             cout<<"hi";
        //             cnt++;
                    
        //         }

        //     }
            
        // }
         

         return solve(nums,k)-solve(nums,k-1);
        
    }
};