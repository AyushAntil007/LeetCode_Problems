class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        //A-1  looping

        //A-2   full multiply


        //A-3  use prefix and suffix

        vector<int>pre(n,1);
        vector<int>suf(n,1);
        
        vector<int>ans(n);

        int prod=1;

        for(int i=0; i<n; i++){
            pre[i]=prod;
            prod*=nums[i];
             
        }
        
        prod=1;

        for(int i=n-1; i>=0; i--){
            suf[i]=prod;
            prod*=nums[i];
            
        }

        for(int i=0;i<n; i++){
            ans[i]=(suf[i]*pre[i]);
        }
        return ans;
    }
};