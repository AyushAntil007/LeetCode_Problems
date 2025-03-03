class Solution {
public:
int binarySearch(vector<int>& arr,int low,int high,int k){
    while(low<=high){
        int mid=(low+high)/2;

        int missing=arr[mid]-(mid+1);  // count missing numbers
        if(missing<k){  
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return k+low;
}
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        // brute force
        // for(int i=0;i<n;i++){
        //     if(arr[i]>k)return k;
        //     else{
        //         k=k+1;
        //     }
        // }
        // return k;


        // optimal sol..BS
        return binarySearch(arr,0,n-1,k);
    }
};