class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());
        int end=nums[0][1];
        int start=nums[0][0];
        
        for(int i=1;i<n;i++){
            
            if(nums[i][0]<=end ){
                end=max(end,nums[i][1]);   // max.....kya pata pura interval hi merge ho jay
            }                              //update end when merge interval exist
            else{
                ans.push_back({start,end});  //store previous interval
                start=nums[i][0];
                end=nums[i][1];
                
            } 
        }
        ans.push_back({start,end});    //store last interval
        return ans;
    }
};