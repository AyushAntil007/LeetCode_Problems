class Solution {
public:
  void solve(int i, vector<int>&nums, vector<vector<int>>&ans,vector<int>&layer,int k){
        if(i==nums.size()){
            if(k==0){
                ans.push_back(layer);
            }
           
            return;
        }
        

        if(nums[i]<=k){
            layer.push_back(nums[i]);
            solve(i,nums,ans,layer,k-nums[i]);
            layer.pop_back();
        }
        
        solve(i+1,nums,ans,layer,k);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>layer;
        
        solve(0,candidates,ans,layer,target);
        return ans;
    }
};