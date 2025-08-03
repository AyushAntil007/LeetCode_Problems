class Solution {
public:
int solve(vector<int>&nums,int goal){
    int n=nums.size();
    int cnt=0;

        int r=0,l=0;
        long long odd=0;

        while(r<n){
            if(nums[r]%2==1)odd++;
            while(l<=r && odd>goal){
                    if(nums[l]%2==1)odd--;
                    l++;    
            }
           
            if(odd<=goal)cnt=cnt+r-l+1;
            r++;
        }
        return cnt;

}
    int numberOfSubarrays(vector<int>& nums, int k) {
         return solve(nums,k)-solve(nums,k-1);   // important
    }
};