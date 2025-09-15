class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        //brute force


        //sort(nums.begin(),nums.end());

        unordered_map<int,int>prefix;
        int n=nums.size();

        for(int i=0; i<n; i++){

            int a=nums[i];
            int b=target-a;


            if(prefix.find(b)!=prefix.end()){
                return { i, prefix[b]};
            }

            prefix[a]=i;

        }
        return {-1,-1};
        
    }
};