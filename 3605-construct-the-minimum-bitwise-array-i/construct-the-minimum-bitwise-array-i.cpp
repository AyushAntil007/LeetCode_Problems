class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;

        int n=nums.size();

        for(int i=0; i<n; i++){

            bool is_satisfy=false;

            for(int j=1; j<=nums[i]; j++){

                if((j|j+1) ==nums[i]){
                    ans.push_back(j);
                    is_satisfy=true;
                    break;
                }
                
            }
            if(!is_satisfy)ans.push_back(-1);
        }

        return ans;
    }
};