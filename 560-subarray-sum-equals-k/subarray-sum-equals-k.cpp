class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count=0;
        int n=arr.size();

        //Approach-1....using for loops

        // for(int i=0;i<n;i++){
        //     int sum=0;
        //    
        //     for(int j=i+1;j<n;j++){
        //         sum+=arr[j];
        //         if(sum==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;


        //Approach-2....using mapping

        unordered_map<int,int>mpp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k)count++;

            int rem=sum-k;
            if(mpp.find(rem)!=mpp.end()){
                count+=mpp[rem];
            }
            mpp[sum]++;
        }
        return count;
    }
};