class Solution {
public:
void solve(int idx,int n,vector<vector<int>>&ans,vector<int>nums){
    if(idx==n-1){
        ans.push_back(nums);      //Approach-2   swapping
        return;
    }
    for(int i=idx;i<n;i++){
        swap(nums[i],nums[idx]);
        solve(idx+1,n,ans,nums);
         swap(nums[i],nums[idx]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();

        solve(0,n,ans,nums);
        return ans;

    }
};