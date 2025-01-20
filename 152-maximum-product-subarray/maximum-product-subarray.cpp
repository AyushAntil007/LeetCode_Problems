class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        //brute force

        // int largeProd=nums[0];
        // for(int i=0;i<n;i++){
        //     int prod=1;
        //     for(int j=i;j<n;j++){
        //          prod=prod*nums[j];
        //          largeProd=max(largeProd,prod);
        //     }
            
        // }
        // return largeProd;

        //optimal sol........kadanes algo

        int posprod=nums[0];
        int negprod=nums[0];
        int tprod=nums[0];  //***important to initialise with nums[0]

        for(int i=1;i<n;i++){
           int temp=max(nums[i],max(posprod*nums[i],negprod*nums[i]));   //keep positive product
            negprod=min(nums[i],min(posprod*nums[i],negprod*nums[i]));  //to store previous negative product arary
            posprod=temp;
            tprod=max(posprod,tprod);
        }
         return tprod;

    }
};