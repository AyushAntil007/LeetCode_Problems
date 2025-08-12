class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        

        // 3 pointers
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        set<vector<int>>st;

        for(int i=0; i<n-2; i++){
            int left=i+1,right=n-1;
            int a=nums[i];

            while(left<right){
                int b=nums[left],c=nums[right];

                if(a+b+c==0){
                    st.insert({a,b,c});
                    left++,right--;
                }
                else if(a+b+c<0)left++;
                else right--;
            }
        }

        
        for(auto it : st)ans.push_back(it);
        
        return ans;
    }
};