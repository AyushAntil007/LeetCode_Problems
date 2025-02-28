class Solution {
public:
    int findDays(vector<int>&weights,int cap){
        int load=0;
        int days=1;  //as shipment is on 1st day
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]<=cap){
                load+=weights[i];
            }
            else{
                days+=1;   //restart with new day
                load=weights[i];
            }
        }
        return days;
    }
    int binarySearch(vector<int>&weights,int days,int low,int high){
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(findDays(weights,mid)<=days){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n=weights.size();
        int mini=*max_element(weights.begin(),weights.end());
        int maxi=accumulate(weights.begin(),weights.end(),0);

        //brute force
        // for(int i=mini;i<=maxi;i++){
        //     if(findDays(weights,i)<=days)return i;
        // }
        // return -1;

        //optimal sol....binary serach
        return binarySearch(weights,days,mini,maxi);
    }
};