class Solution {
public:
void solve(int i,int n,vector<int>sub,vector<vector<int>>&ans,vector<int>&nums){
    if(i==n){
        ans.push_back(sub);
        return;                               //Approach-1   Set
    }
    sub.push_back(nums[i]);
    solve(i+1,n,sub,ans,nums);
    sub.pop_back();
    solve(i+1,n,sub,ans,nums);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<vector<int>>ans;
        vector<int>sub;
        int n=nums.size();
        solve(0,n,sub,ans,nums);
        set<vector<int>> uniqueSubsets(ans.begin(), ans.end());
        ans.assign(uniqueSubsets.begin(), uniqueSubsets.end());
        return ans;
    }
};