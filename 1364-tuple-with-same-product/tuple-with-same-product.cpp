class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<4)return 0;
        int count=0;
        //brute force

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             for(int l=k+1;l<n;l++){
        //                 
        //                     if (nums[i] * nums[j] == nums[k] * nums[l]) count += 8;
        //                     else if (nums[i] * nums[k] == nums[j] * nums[l]) count += 8;
        //                     else if (nums[i] * nums[l] == nums[j] * nums[k]) count += 8;
        //                 
                        
        //             }
        //         }
        //     }
        // }

        //hashing

        unordered_map<int,int>mpp;
       
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int product=nums[i]*nums[j];
               if(mpp.find(product)!=mpp.end()){
                count+=mpp[product]*8;
                
               }
                mpp[product]++;
            }
        }
        
        return count;
    }
};