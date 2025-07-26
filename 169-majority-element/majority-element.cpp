class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int cnt=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[i]==nums[j])cnt++;
        //     }
        //     if(cnt>n/2)return nums[i];
        // }
        // return -1;


        ///hasing

        // unordered_map<int,int>mpp;
        // for(int i=0;i<n;i++){
        //     mpp[nums[i]]++;
        // }

        // for(auto it: mpp){
        //     if(it.second>n/2)return it.first;
        // }
        // return -1;

        //optimal 

        int elt=nums[0];
        int cnt=1;

        for(int i=1;i<n;i++){
            if(nums[i]==elt)cnt++;
            else{
                cnt--;
                if(cnt==0){
                    elt=nums[i];
                    cnt=1;
                }
            }
        }
        return elt;
    }
    
};