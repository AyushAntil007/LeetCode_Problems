class Solution {
public:

    void solve(int i, vector<int>&nums, vector<vector<int>>&ans,vector<int>&layer){
        if(i==nums.size()){
            ans.push_back(layer);
            return;
        }

        layer.push_back(nums[i]);
        solve(i+1,nums,ans,layer);
        layer.pop_back();
        solve(i+1,nums,ans,layer);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>layer;

        solve(0,nums,ans,layer);
        return ans;
    }
};